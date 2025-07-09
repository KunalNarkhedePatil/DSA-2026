
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<vector>
class Array
{
protected:
    int iSize;
    int *Arr;

public:
    Array(int iSize = 5) : iSize(iSize), Arr(new int[iSize]) {}

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
    std::vector<int> TwoSum(int iTarget)
    {
       std::unordered_map<int,int> map;

       for(int i=0;i<iSize;i++)
       {
           int iNo=Arr[i];
           int iMore=iTarget-iNo;

           if(map.find(iMore)!=map.end())
           {
                return {map[iMore],i};
           }
           map[iNo]=i;
       }

       return {-1,-1};
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

    std::vector<int> vecRet = obj.TwoSum(6);

    std::cout << "Two Sum at indexs :" << vecRet[0] << " And " << vecRet[1] << std::endl;
    return 0;
}
