#include <iostream>
#include <map>

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
        {
            return *this;
        }
        delete[] Arr;
        this->iSize = other.iSize;
        this->Arr = new int[iSize];
        for (int i = 0; i < iSize; i++)
        {
            this->Arr[i] = other.Arr[i];
        }

        return *this;
    }

    void Accept() const
    {
        for (int i = 0; i < iSize; i++)
        {
            std::cin >> Arr[i];
        }
    }

    void Display() const
    {
        for (int i = 0; i < getSize(); i++)
        {
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    }
    int *getArr() const
    {
        return Arr;
    }
    int getSize() const
    {
        return iSize;
    }
};
class ArrayDemo : public Array
{
public:
    ArrayDemo(int iSize) : Array(iSize) {}

    void PlusOne()
    {
        for (int i = getSize() - 1; i >= 0; i--)
        {
            if (Arr[i] < 9)
            {
                Arr[i] = Arr[i] + 1;
                return;
            }
            Arr[i] = 0;
        }

        int *newArr = new int[iSize + 1];

        newArr[0] = 1;
        for (int i = 1; i <= iSize; i++)
        {
            newArr[i] = 0; 
        }

        delete[] Arr;
        Arr = newArr;
        iSize++;
    }
};

int main()
{
    int iSize = 0;

    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize);

    std::cout << "Enter element:\n";
    obj.Accept();

    int *Arr = obj.getArr();

    std::cout << "Array element:\n";
    obj.Display();

    obj.PlusOne();

    std::cout << "After Plus One:" << std::endl;

    obj.Display();
}