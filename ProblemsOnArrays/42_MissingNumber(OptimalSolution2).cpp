#include <iostream>
#include <algorithm>
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

    int findMissingNumber(int iSize)
    {
        // Using XOR

        // Theroy:-

        // Suppose  2^2=0,2^2^2^2=0,2^2^2^2^2^2=0,0^3=3
        // when we XOR with same number its become 0 and with O with other its become that number only
        int XOR1 = 0;
        int XOR2 = 0;
        for (int i = 0; i < iSize; i++)
        {
            XOR1 = XOR1 ^ i;
        }
        for (int i = 0; i < iSize - 1; i++)
        {
            XOR2 = XOR2 ^ Arr[i];
        }

        return XOR1 ^ XOR2;
    }
};

int main()
{
    int iSize;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize - 1);

    std::cout << "Enter elements:\n";
    obj.Accept();

    std::cout << "Array elements:\n";
    obj.Display();

    int iRet = obj.findMissingNumber(iSize);

    std::cout << "Missing number from array is :" << iRet << std::endl;
    return 0;
}
