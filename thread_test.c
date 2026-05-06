#include<stdio.h>
#include<stdlib.h>

typedef char ElemTtype;
typedef struct treenode
{
    ElemTtype data;
    struct treenode* lchild;
    struct treenode* rchild;
    int ltag;
    int rtag;
}Treenode;

typedef Treenode* BigTree;

char str[] = "ABDH##I##EJ###CF##G##";
int index = 0;
Treenode* prev;

void createTree(BigTree* T)
{
    
    (*T) = (BigTree)malloc(sizeof(Treenode));
    char ch = str[index];
    index++;
    if(ch == '#' || ch == '\0')
    {
        (*T) = NULL;
    }
    else
    {
        (*T)->data = ch;
        createTree(&((*T)->lchild));
        if((*T)->lchild != NULL)
        {
            (*T)->ltag = 0;
        }
        createTree(&((*T)->rchild));
        if((*T)->lchild != NULL)
        {
            (*T)->rtag = 0;
        }
    }
}

void headthread(BigTree* head, BigTree T)
{
    (*head) = (BigTree)malloc(sizeof(Treenode));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);
    if(T == NULL)
    {
        (*head)->lchild = (*head);
    }
    else
    {
        (*head)->lchild = T;
        prev = (*head);

        
        prev->rtag = 1;
        prev->rchild = (*head);
        (*head)->rchild = prev;
    }
}






int main(int argc, char* argv[])
{
    Treenode* tree = NULL;
    Treenode* head = NULL;
    createTree(&tree);
    headthread(&head, &tree);

    return 0;
}