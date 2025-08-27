
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
        std::vector<int> vecZero;
        std::vector<int> vecOne;
        std::vector<int> vecTwo;
       
        for (int i = 0; i < iSize; i++)
        {
            if (Arr[i] == 0)
            {
                vecZero.push_back(Arr[i]);
            }
            else if (Arr[i] == 1)
            {
                vecOne.push_back(Arr[i]);
            }
            else
            {
                vecTwo.push_back(Arr[i]);
            }
        }

        int i = 0;
        while (vecZero.size() != 0)
        {
            Arr[i] = vecZero.back();
            vecZero.pop_back();
            i++;
        }

        while (vecOne.size() != 0)
        {
            Arr[i] = vecOne.back();
            vecOne.pop_back();
            i++;
        }
        while (vecTwo.size() != 0)
        {
            Arr[i] = vecTwo.back();
            vecTwo.pop_back();
            i++;
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
