#include <iostream>

class Array
{
protected:
    int iSize;
    int* Arr;

public:
    Array(int iSize) : iSize(iSize), Arr(new int[iSize]) {}

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

    int reverseNumber(int iNo)
    {
        int iRev=0;

        while(iNo!=0)
        {
            iRev=iRev*10+iNo%10;
            iNo=iNo/10;
        }
        return iRev;
    }
    void ReverseAllElementsInArray()
    {
        for(int i=0;i<iSize;i++)
        {
            Arr[i]=reverseNumber(Arr[i]);
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

    obj.ReverseAllElementsInArray();

    std::cout<<"After ReverseAll Elemenets in Arary :"<<std::endl;

    obj.Display();
    return 0;
}
