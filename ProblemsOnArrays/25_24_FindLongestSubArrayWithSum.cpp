#include <iostream>
#include <vector>

class Array
{
protected:
    int iSize;
    int *Arr;

public:
    Array(int iSize) : iSize(iSize), Arr(new int[iSize]) {}

    virtual ~Array()
    {
        delete[] Arr;
        Arr = nullptr;
    }

    Array(const Array &other)
    {
        this->iSize = other.iSize;
        this->Arr = new int[iSize];
        for (int i = 0; i < iSize; i++)
        {
            this->Arr[i] = other.Arr[i];
        }
    }

    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;

        delete[] this->Arr;
        this->iSize = other.iSize;
        this->Arr = new int[iSize];

        for (int i = 0; i < iSize; i++)
        {
            this->Arr[i] = other.Arr[i];
        }

        return *this;
    }

    void Accept()
    {
        for (int i = 0; i < iSize; i++)
        {
            std::cin >> Arr[i];
        }
    }

    void Display() const
    {
        for (int i = 0; i < iSize; i++)
        {
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

class ArrayDemo : public Array
{
public:
    ArrayDemo(int iSize) : Array(iSize) {}

    int longestSubarrayWithSum(int K)
    {
        int maxLen = 0;
        for (int i = 0; i < iSize; i++)
        {
            int currSum = 0;

            for (int j = i; j < iSize; j++)
            {
                currSum = currSum + Arr[j];

                if (currSum == K)
                {
                    int len = j - i + 1;

                    if (len > maxLen)
                    {
                        maxLen = len;
                    }
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    int iSize;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize);

    std::cout << "Enter elements:\n";
    obj.Accept();

    std::cout << "Array elements:\n";
    obj.Display();

    int K = 0;

    std::cout << "Enter the target element" << std::endl;

    std::cin >> K;

    int res = obj.longestSubarrayWithSum(K);

    std::cout << "Output:" << res << std::endl;
    return 0;
}
