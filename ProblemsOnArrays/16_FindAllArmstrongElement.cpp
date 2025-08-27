#include <iostream>

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

    static int CountDigitInNumber(int iNo)
    {
        int iCnt = 0;

        while (iNo != 0)
        {
            iCnt++;
            iNo = iNo / 10;
        }

        return iCnt;
    }
    bool checkArmstrongNumber(int iNo)
    {
        int iCntDigit = CountDigitInNumber(iNo);

        int iMult = 1;
        int iSum = 0;
        int iTemp = iNo;
        while (iNo != 0)
        {
            iMult = 1;
            int iDigit = iNo % 10;
            for (int i = 1; i <= iCntDigit; i++)
            {
                iMult = iMult * iDigit;
            }
            iSum = iSum + iMult;
            iNo=iNo/10;
        }
        if (iTemp == iSum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void findAllArmstrongNumber()
    {
        bool bFlag = false;
        for (int i = 0; i < iSize; i++)
        {
            if (checkArmstrongNumber(Arr[i]))
            {
                bFlag=true;
                std::cout << Arr[i] << " ";
            }
        }
        if (bFlag == false)
        {
            std::cout << "There is no armstrong number element in array" << std::endl;
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

    obj.findAllArmstrongNumber();
    return 0;
}
