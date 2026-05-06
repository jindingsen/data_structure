#include<stdio.h>
#include<stdlib.h>


/* void func(int* temp)
{
    *temp = 20;
}


int main(int argc, char* argv[])
{
    int a = 10;
    func(&a);
    printf("a = %d", a);
    return 0;
} */

void func(int** temp)
{   
    *temp = (int*)malloc(sizeof(int));
    //**temp = 100;
}


int main(int argc, char* argv[])
{
    int* p = NULL;
    func(&p);
    printf("%p", p);
    return 0;
}