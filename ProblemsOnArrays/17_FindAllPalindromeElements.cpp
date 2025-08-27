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

    bool checkNumberPalindrome(int iNo)
    {
        //First Find Reverse Number

        int Temp=iNo;
        int iRev=0;
        while(iNo!=0)
        {
            iRev=(iRev*10)+iNo%10;
            iNo=iNo/10;
        }
        if(iRev==Temp)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

   
    void FindAllPalindromeElements()
    {
        bool bFlag=false;
        for(int i=0;i<iSize;i++)
        {
            if(checkNumberPalindrome(Arr[i]))
            {
                bFlag=true;
                std::cout<<Arr[i]<<" ";
            }
        }
        if(bFlag==false)
        {
            std::cout << "There is no Palindrome number element in array.";
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

    obj.FindAllPalindromeElements();
    return 0;
}
