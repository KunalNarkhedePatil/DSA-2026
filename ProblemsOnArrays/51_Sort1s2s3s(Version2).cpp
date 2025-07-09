
#include <iostream>
#include <algorithm>
#include <vector>
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

    void sortArray()
    {
        int iCntZero = 0;
        int iCntOne = 0;
        int iCntTwo = 0;

        for (int i = 0; i < iSize; i++)
        {
            if (Arr[i] == 0)
            {
                iCntZero++;
            }
            else if (Arr[i] == 1)
            {
                iCntOne++;
            }
            else
            {
                iCntTwo++;
            }
        }

        for (int i = 0; i < iSize; i++)
        {
            if (iCntZero != 0)
            {
                Arr[i] = 0;
                iCntZero--;
            }
            else if (iCntOne != 0)
            {
                Arr[i] = 1;
                iCntOne--;
            }
            else
            {
                Arr[i] = 2;
                iCntTwo--;
            }
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

    obj.sortArray();

    std::cout << "After Sorting array is:" << std::endl;

    obj.Display();
    return 0;
}
