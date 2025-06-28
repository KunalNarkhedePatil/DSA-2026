//9, 4, -2, -1, 5, 0, -5, -3, 2
#include <iostream>
#include<vector>
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

    void rearrange()
    {
        std::vector<int> vecPos;
        std::vector<int> vecNeg;
        for(int i=0;i<iSize;i++)
        {
            if(Arr[i]>=0)
            {
                vecPos.push_back(Arr[i]);
               
            }
            else
            {
                vecNeg.push_back(Arr[i]);
            }
        }

        int i=0;
        int j=0;
        int k=0;

        while(i<vecPos.size() && j<vecNeg.size())
        {
            Arr[k++]=vecPos[i++];
            Arr[k++]=vecNeg[j++]; 
        }

        while(i<vecPos.size())
        {
            Arr[k++]=vecPos[i++];
        }

        while(j<vecNeg.size())
        {
            Arr[k++]=vecNeg[j++]; 
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

    obj.rearrange();

    std::cout<<"After rearranginng Positive Negative Alternative:"<<std::endl;

    obj.Display();

    return 0;
}
