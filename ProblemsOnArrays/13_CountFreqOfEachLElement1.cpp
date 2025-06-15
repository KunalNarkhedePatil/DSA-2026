#include<iostream>

class Array
{
    protected:
    int iSize;
    int *Arr;

    public:

    Array(int iSize):iSize(iSize),Arr(new int[iSize]){}
    virtual ~Array()
    {
        delete[] Arr;
        Arr=nullptr;
    }

    Array(const Array &other)
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
        delete[] Arr;
        this->iSize=other.iSize;
        this->Arr=new int[iSize];
        for(int i=0;i<iSize;i++)
        {
            this->Arr[i]=other.Arr[i];
        }


        return *this;
    }

    void Accept() const
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
    int* getArr()
    {
        return Arr;
    }
};
class ArrayDemo:public Array
{
    public:
  
    ArrayDemo(int iSize):Array(iSize){}
   
    void CountFreqOfEachElement()
    {
        int *Freq=new int[iSize];

        for(int i=0;i<iSize;i++)
        {
            Freq[i]=-1;
        }

        int i=0, j=0,Count=0;
        for(i=0;i<iSize;i++)
        {
            if(Freq[i]==0)
            {
                continue;
            }
            Count=1;
            for(j=i+1;j<iSize;j++)
            {
                if(Arr[i]==Arr[j])
                {
                    Count++;
                    Freq[j]=0;
                }
            }

            if(Freq[i]!=0)
            {
                Freq[i]=Count;
            }
        }

        for(int i=0;i<iSize;i++)
        {
            if(Freq[i]!=0)
            {
                std::cout<<Arr[i]<<" occurs "<<Freq[i]<<" times "<<std::endl;
            }
        }

        delete[] Freq;
    }
};

int main()
{
    int iSize=0;

    std::cout<<"Enter size of array: ";
    std::cin>>iSize;

    ArrayDemo obj(iSize);

    std::cout<<"Enter element:\n";
    obj.Accept();

    int *Arr=obj.getArr();

    std::cout<<"Array element:\n";
    obj.Display();

    std::cout<<"Frequency of each element:"<<std::endl;

    obj.CountFreqOfEachElement();

}