#include<iostream>
using namespace std;

int main()
{
    int iNo=153;

    int iCnt=0;
    while(iNo>=9)
    {
        iCnt++;
        iNo/=10;
    }

    cout<<"Number of digit in iNo:"<<iCnt<<endl;
    return (0);
}