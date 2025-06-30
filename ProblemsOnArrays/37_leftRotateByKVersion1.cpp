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

    void leftRotateByK(int K)
    {

        K = K % iSize;

        std::vector<int> temp;

        for (int i = 0; i < K; i++)
        {
            temp.push_back(Arr[i]);
        }

        // Shifting

        for (int i = K; i < iSize; i++)
        {
            Arr[i - K] = Arr[i];
        }

        int j = 0;
        for (int i = iSize - K; i < iSize; i++)
        {
            Arr[i] = temp[j];
            j++;
        }
    }
};

int main()
{
    int iSize = 0, K = 0;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize);

    std::cout << "Enter elements:\n";
    obj.Accept();

    std::cout << "Array elements:\n";
    obj.Display();

    std::cout << "Enter the K:" << std::endl;
    std::cin >> K;

    obj.leftRotateByK(K);

    std::cout << "After Rotating Left By K" << std::endl;

    obj.Display();

    return 0;
}
