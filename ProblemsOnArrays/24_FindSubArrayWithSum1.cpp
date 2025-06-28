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

    std::vector<int> subarraySum(int target)
    {
        for (int i = 0; i < iSize; i++)
        {
            int currSum = Arr[i];

            if (currSum == target)
            {
                return {i + 1, i + 1};
            }

            for (int j = i + 1; j < iSize; j++)
            {
                currSum = currSum+Arr[j];

                if (currSum == target)
                {
                    return {i + 1, j + 1};
                }
            }
        }
        return {-1};
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

    int target=0;

    std::cout<<"Enter the target element"<<std::endl;

    std::cin>>target;

    std::vector<int> res=obj.subarraySum(target);

    std::cout<<"Output:"<<res[0]<<" "<<res[1]<<std::endl;
    return 0;
}
