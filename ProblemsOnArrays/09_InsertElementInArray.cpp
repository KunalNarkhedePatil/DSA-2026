#include <iostream>

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

    int *getArr() const
    {
        return Arr;
    }

    void Display(int Arr[]) const
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

    void InsertElementInArray(int iNo, int iPos)
    {
        if (iPos < 1 || iPos > iSize + 1)
        {
            std::cout << "Invalid Index..." << std::endl;
            exit(-1);
        }

        int *newArr = new int[iSize + 1];

        for (int i = 0; i < iPos - 1; i++)
        {
            newArr[i] = Arr[i];
        }

        newArr[iPos - 1] = iNo;

        for (int i = iPos; i <= iSize; i++)
        {
            newArr[i] = Arr[i];
        }

        delete[] Arr;
        Arr = newArr;
        iSize++;
    }
};

int main()
{
    int iSize = 0;
    int iNo = 0;
    int iPos = 0;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize);

    std::cout << "Enter elements:\n";
    obj.Accept();

    int *Arr = obj.getArr();
    std::cout << "Array elements:\n";
    obj.Display(Arr);

    std::cout << "Enter the iNo want to insert :" << std::endl;
    std::cin >> iNo;

    std::cout << "Enter the position" << std::endl;
    std::cin >> iPos;

    obj.InsertElementInArray(iNo, iPos);

    Arr = obj.getArr();

    std::cout << "After Insert Array is :" << std::endl;

    obj.Display(Arr);
    return 0;
}
