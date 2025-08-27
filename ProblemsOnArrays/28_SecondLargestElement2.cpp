#include <iostream>
#include <algorithm>
class Array
{
protected:
    int iSize;
    int* Arr;

public:
    Array(int iSize=5) : iSize(iSize), Arr(new int[iSize]) {}

    virtual ~Array()
    {
        delete[] Arr;
        Arr = nullptr;
    }

    Array(const Array& other)
    {
        this->iSize = other.iSize;
        this->Arr = new int[iSize];
        for (int i = 0; i < iSize; i++)
        {
            this->Arr[i] = other.Arr[i];
        }
    }

    Array& operator=(const Array& other)
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

    int FindLargest()
    {
        int iMax=Arr[0];
        for(int i=0;i<iSize;i++)
        {
            if(Arr[i]>iMax)
            {
                iMax=Arr[i];
            }
        }
        return iMax;
    }

    //1 2 3 4 5 5
    int findSecondLargest()
    {
        int iMax=FindLargest();

        std::sort(Arr,Arr+iSize);

        std::cout<<"Max:"<<iMax<<std::endl;

        for(int i=iSize-2;i>=0;i--)
        {
            if(iMax != Arr[i]) 
            {
                return Arr[i];
            }
        }
        return -1;
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

    int iRet=obj.findSecondLargest();

    std::cout<<"Second largest element is :"<<iRet<<std::endl;
    return 0;
}
