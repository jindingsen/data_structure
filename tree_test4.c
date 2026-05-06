#include<stdio.h>
#include<stdlib.h>
//在github上面修改不知道能不能pull下来
typedef char Elemtype;
typedef struct treenode
{
    Elemtype data;
    struct treenode* lchild;
    struct treenode* rchild;
    int ltag;
    int rtag;
}Treenode;

typedef Treenode* BigTree;

char str[] = "ABDH##I##EJ###CF##G##";
int index = 0;
BigTree pre;

void createTree(BigTree* mytree)
{
    *mytree =(Treenode*)malloc(sizeof(Treenode));
    char ch = str[index];
    index++;
    if(ch == '#' | ch == '\0')
    {
        *mytree = NULL;
    }
    else
    {
        createTree(&((*mytree)->lchild));
        if(((*mytree)->lchild) == NULL)
        {
            (*mytree)->ltag = 0;
        }
        createTree(&((*mytree)->rchild));
        if(((*mytree)->rchild) == NULL)
        {
            (*mytree)->rtag = 0;
        }
    }
}


void threadTree(BigTree mytree)
{
    if(mytree != NULL)
    {
        threadTree(mytree->lchild);
        if(mytree->lchild == NULL)
        {
            mytree->ltag = 1;
            mytree->lchild = pre;
        }
        if(pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = mytree;
        }
        pre = mytree;
        threadTree(mytree->rchild);
    }
}

void threadFrame(BigTree mytree, BigTree* head)
{
    
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = *head;
    if(mytree == NULL)
    {
        *head = NULL;
    }
    else
    {
        (*head)->lchild = mytree;
        pre = (*head);
        threadTree(mytree);
        pre->rtag = 1;
        pre->rchild = (*head);
        (*head)->rchild = pre;
    }
}



int main(int argc, char* argv[])
{
    Treenode* tree = NULL;
    Treenode* head = NULL;
    createTree(&tree);
    threadFrame(&tree, head);

    return 0;
}
