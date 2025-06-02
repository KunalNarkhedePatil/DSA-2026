#include<iostream>

class Array
{
    private:

    int iSize;
    int *Arr;

    public:

    Array(int _iSize):iSize(_iSize),Arr(new int[iSize]){}

    ~Array()
    {
        delete[] Arr;
        Arr=nullptr;
    }

    Array(const Array& other)
    {
        this->iSize=other.iSize;
        this->Arr=new int[iSize];
        
        for(int i=0;i<iSize;i++)
        {
            this->Arr[i]=other.Arr[i];
        }
    }

    Array& operator=(const Array& other)
    {

        if(this==&other)
        {
            return *this;
        }
        delete[] this->Arr;
        this->Arr=0;
        
        this->iSize=other.iSize;

        for(int i=0;i<iSize;i++)
        {
            this->Arr[i]=other.Arr[i];
        }

        return *this;
    }

    void Accept()
    {
        for(int i=0;i<iSize;i++)
        {
            std::cin>>Arr[i];
        }

    }
    void Display() const
    {
        for(int i=0;i<iSize;i++)
        {
            std::cout<<Arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void printAllNegative()
    {
        int iFlag=0;

        for(int i=0;i<iSize;i++)
        {
            if(Arr[i]<0)
            {
                iFlag=1;
                std::cout<<Arr[i]<<" ";
            }
        }

        if(!iFlag)
        {
             std::cout<<"None"<<std::endl;

        }
        else
        {
            std::cout<<std::endl;
        }
    }


};
int main()
{

    int iSize=0;

    std::cout<<"Enter the Size of Array "<<std::endl;
    std::cin>>iSize;
    Array obj(iSize);

    std::cout<<"Enter the element in the array"<<std::endl;
    obj.Accept();

    std::cout<<"Entered Elements"<<std::endl;

    obj.Display();

    std::cout<<"Negative Elements Are"<<std::endl;
    obj.printAllNegative();

    return (0);
}