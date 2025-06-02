#include <iostream>

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

    int* getArr()
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


    void DeleteElementInArray(int iPos)
    {
        if(iPos<1 || iPos>iSize+1)
        {
            std::cout<<"Invalid Index...."<<std::endl;
            exit(-1);
        }

        for(int i=iPos;i<iSize;i++)
        {
            Arr[i]=Arr[i+1];
        }

        Arr=(int *)realloc(Arr,sizeof(int)*iSize-1);
        iSize--;
    }

   
};

int main()
{
    int iSize;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    ArrayDemo obj(iSize);

    int *Arr=obj.getArr();
    std::cout << "Enter elements:\n";
    obj.Accept();

    std::cout << "Array elements:\n";
    obj.Display(Arr);

    int iPos=0;

    std::cout<<"Enter the position want to delete element:"<<std::endl;
    std::cin>>iPos;

    obj.DeleteElementInArray(iPos);

    std::cout<<"After Deleting Array is :"<<std::endl;
    Arr=obj.getArr();
    obj.Display(Arr);

   
    return 0;
}
