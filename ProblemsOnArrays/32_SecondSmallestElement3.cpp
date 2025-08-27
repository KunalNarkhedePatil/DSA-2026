#include <iostream>
#include<algorithm>
#include<climits>
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

   
    int findSecondSmallest()
    {
        
        int iMin=INT_MAX;

        int iSecondMin=INT_MAX;

        for(int i=0;i<iSize;i++)
        {
            if(Arr[i]<iMin)
            {
                iSecondMin=iMin;
                iMin=Arr[i];
            }
            else if(Arr[i] < iSecondMin && Arr[i] > iMin)
            {
                iSecondMin=Arr[i];
            }
        }
       if(iSecondMin==INT_MAX)
       {
          return -1;
       }
       else
       {
          return iSecondMin;
       }
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

    int iRet = obj.findSecondSmallest();

    std::cout << "Second Minimum element is :" << iRet << std::endl;
    return 0;
}
