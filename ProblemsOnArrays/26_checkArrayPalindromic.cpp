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

    bool checkArrayPalindromic()
    {
        int iStart = 0;
        int iEnd = iSize - 1;

        while (iStart <= iEnd)
        {
            if (Arr[iStart] != Arr[iEnd])
            {
                return false;
            }
            iStart++;
            iEnd--;
        }

        return true;
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

    bool bRet=obj.checkArrayPalindromic();

    if(bRet==true)
    {
        std::cout<<"Given Array is Palindromic"<<std::endl;
    }
    else
    {
        std::cout<<"Given Array is not Palindromic"<<std::endl;
    }

    return 0;
}
