#include <iostream>

int main()
{
    for(int i=1;i<=10;i++)
    {
        for(int i=1;i<=10;i++) std::cout<<"*";
        std::cout<<"\n";
    }

    //为什么我自己写的for嵌套两个i调用却没有出现问题...
    return 0;
}