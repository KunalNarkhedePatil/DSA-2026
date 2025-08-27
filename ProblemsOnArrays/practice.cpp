#include<iostream>
#include<vector>

int main()
{
    std::vector<int> vec={1,2,3,4,5};

    for(std::vector<int>::iterator iter=vec.begin();iter!=vec.end();++iter)
    {
        std::cout<<*iter<<" ";
    }
    std::cout<<std::endl;

}