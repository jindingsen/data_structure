#include<stdio.h>
#include<stdlib.h>

int func(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int my_recurse(int n)
{
    int sum = 0;
    if(n == 0)
    {
        sum = 0;
    }
    else
    {
        sum = n + my_recurse(n - 1);
    }
    return sum;
}

int main(int argc, char* argv[])
{

    int result = func(10);
    int result2 = my_recurse(20);
    printf("和是：%d\n", result2);
    return 0;
}