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
        Arr=NULL;


    }

    Array(const Array& other)
    {
        this->iSize=other.iSize;
        Arr=new int[other.iSize];

        for(int i=0;i<iSize;i++)
        {
            Arr[i]=other.Arr[i];
        }

    }

    Array& operator=(const Array& other)
    {
        this->iSize=other.iSize;

        for(int i=0;i<iSize;i++)
        {
            this->Arr[i]=other.Arr[i];
            //*(Arr+i)=*other.Arr+i;
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

};
int main()
{

    int iSize=0;

    std::cout<<"Enter the Size of array"<<std::endl;
    std::cin>>iSize;

    if(iSize<=0)
    {
        std::cout<<"Enter the valid size of array"<<std::endl;
        exit(-1);
    }

    Array obj(iSize);

    std::cout<<"Entet the element in the array"<<std::endl;
    obj.Accept();

    std::cout<<"Entered Element"<<std::endl;

    obj.Display();

    return (0);
}