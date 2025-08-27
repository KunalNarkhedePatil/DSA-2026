#include <iostream>
#include<algorithm>

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

    void reverseArray(int iStart,int iEnd)
    {
        while(iStart<=iEnd)
        {
            int iTemp=Arr[iStart];
            Arr[iStart]=Arr[iEnd];
            Arr[iEnd]=iTemp;
            iStart++;
            iEnd--;
        }
    }
    void leftRotateByK(int K)
    {
        reverseArray(0,K-1);
        reverseArray(K,iSize-1);
        reverseArray(0,iSize-1);

       // std::reverse(Arr,Arr+K);
        //std::reverse(Arr+K,Arr+iSize);
       // std::reverse(Arr,Arr+iSize);
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
