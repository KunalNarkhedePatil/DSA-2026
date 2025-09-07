#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <curl/curl.h>   // libcurl header

// -------------------------
// Step 1: INI Parsing
// -------------------------
std::vector<std::string> GetSections(const std::string &iniPath) {
    char buffer[4096];
    DWORD chars = GetPrivateProfileSectionNamesA(buffer, sizeof(buffer), iniPath.c_str());

    std::vector<std::string> sections;
    const char* p = buffer;
    while (*p) {
        sections.push_back(p);
        p += strlen(p) + 1;
    }
    return sections;
}

std::map<std::string, std::string> GetSectionData(const std::string &section, const std::string &iniPath) {
    char buffer[4096];
    GetPrivateProfileSectionA(section.c_str(), buffer, sizeof(buffer), iniPath.c_str());

    std::map<std::string, std::string> data;
    const char* p = buffer;
    while (*p) {
        std::string entry(p);
        size_t eq = entry.find('=');
        if (eq != std::string::npos) {
            std::string key = entry.substr(0, eq);
            std::string value = entry.substr(eq + 1);
            data[key] = value;
        }
        p += strlen(p) + 1;
    }
    return data;
}

// -------------------------
// Step 2: JSON Builder (manual, no libs)
// -------------------------
std::string Escape(const std::string &s) {
    std::string out;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\"') out += "\\\"";
        else out += s[i];
    }
    return out;
}

std::string ConvertToJSON(const std::string &iniPath) {
    std::vector<std::string> sections = GetSections(iniPath);
    std::string json = "{";

    for (size_t i = 0; i < sections.size(); ++i) {
        const std::string &sec = sections[i];
        json += "\"" + Escape(sec) + "\":{";

        std::map<std::string, std::string> data = GetSectionData(sec, iniPath);
        size_t count = 0;
        for (std::map<std::string, std::string>::iterator it = data.begin(); it != data.end(); ++it, ++count) {
            std::string key = it->first;
            std::string value = it->second;

            // Split "12|234 MB"
            std::string fileCount, fileSize;
            size_t pos = value.find('|');
            if (pos != std::string::npos) {
                fileCount = value.substr(0, pos);
                fileSize = value.substr(pos + 1);
            }

            json += "\"" + Escape(key) + "\":{";
            json += "\"count\":\"" + Escape(fileCount) + "\",";
            json += "\"size\":\"" + Escape(fileSize) + "\"}";
            if (count + 1 < data.size()) json += ",";
        }
        json += "}";
        if (i + 1 < sections.size()) json += ",";
    }

    json += "}";
    return json;
}

// -------------------------
// Step 3: Send JSON via libcurl
// -------------------------
bool SendJSON(const std::string &url, const std::string &jsonStr) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) return false;

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)jsonStr.size());

    // Debug output
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return (res == CURLE_OK);
}

// -------------------------
// Step 4: Main
// -------------------------
int main() {
    std::string iniPath = "C:\\path\\to\\data.ini";

    std::string jsonStr = ConvertToJSON(iniPath);
    std::cout << "Generated JSON:\n" << jsonStr << std::endl;

    // Example: POST to http://localhost:8080/api/data
    if (SendJSON("http://localhost:8080/api/data", jsonStr)) {
        std::cout << "JSON sent successfully!\n";
    } else {
        std::cout << "Failed to send JSON.\n";
    }

    return 0;
}
