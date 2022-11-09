#include"Time.h"
#include<iostream>

int main()
{
    Time t(23, 59, 59);
    Time b;
    std::cin >> b;

    Time sum = t + b.get_Abs_Sec();
    std::cout << "sum: " << sum;
    return 0;
}