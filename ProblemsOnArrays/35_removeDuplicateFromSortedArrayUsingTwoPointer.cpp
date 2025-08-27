//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1680658450/
#include <iostream>
#include<set>
class Array
{
protected:
    int iSize;
    int *Arr;

public:
    Array(int iSize = 5) : iSize(iSize), Arr(new int[iSize]) {}

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

   
   int removeDuplicateFromSortedArray()
   {
      int i=0;


      for(int j=1;j<iSize;j++)
      {
        if(Arr[j]!=Arr[i])
        {
            Arr[i+1]=Arr[j];
            i++;
        }
      }

      return i+1;
   }

   void Display(int size)
   {
      for(int i=0;i<size;i++)
      {
          std::cout<<Arr[i]<<" ";
      }
      std::cout<<std::endl;
   }


};

int main()
{
    int iSize;
    std::cout << "Enter size of array: ";
    std::cin >> iSize;

    Array *pObj=new ArrayDemo(iSize);

    std::cout << "Enter elements:\n";
    pObj->Accept();

    std::cout << "Array elements:\n";
    pObj->Display();

    int iRet = reinterpret_cast<ArrayDemo*>(pObj)->removeDuplicateFromSortedArray();

    std::cout<<"iRet:"<<iRet<<std::endl;

    std::cout<<"Check After remove duplicate unique element:"<<std::endl;

    reinterpret_cast<ArrayDemo*>(pObj)->Display(iRet);
    return 0;
}
