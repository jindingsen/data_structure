#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct threadnode
{
    ElemType data;
    struct threadnode* lchild;
    struct threadnode* rchild;
    int ltag;
    int rtag;
}ThreadNode;

typedef ThreadNode* ThreadTree;




char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;


int main(int argc, char* argv[])
{



    return 0;
}
