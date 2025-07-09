//With Positive Integer

#include <iostream>
#include<algorithm>
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
   /// 1 2 3 1 1 1 1 3 3  K=6
    int longestSubArraySumWithK(int K)
    {
        int iRight=0;
        int iLeft=0;
        int iMaxLen=0;
        int iSum=Arr[0];
        while(iRight<iSize)
        {
            while(iLeft<=iRight &&  iSum>K)
            {
                iSum=iSum-Arr[iLeft];
                iLeft++;
            }
            if(iSum==K)
            {
                iMaxLen=std::max(iMaxLen,iRight-iLeft+1);
            }
            iRight++;
            if(iRight<iSize)
            {
                iSum=iSum+Arr[iRight];
            }
        }
        return iMaxLen;
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

    int iRet = obj.longestSubArraySumWithK(6);

    std::cout << "Longest SubArray Sum With K is:" << iRet << std::endl;
    return 0;
}
