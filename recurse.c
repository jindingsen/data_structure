#include<stdio.h>
#include<stdlib.h>

int my_recurse(int n)
{
    int sum = 0;
    if(n <= 0)
    {
        return 0;
    }

    else
    {
        sum = n + my_recurse(n-1);
    }
    return sum;
}




int main(int argc, char *argv[])
{
    int result = 0;
    result = my_recurse(10);
    printf("Result: %d\n", result);
    return 0;

}