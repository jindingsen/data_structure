#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct treenode
{
    ElemType data;
    struct treenode* lchild;
    struct treenode* rchild;
}Treenode;

typedef Treenode* BigTree;


void preTree(BigTree tree)
{
    if(tree == NULL)
    {
        return;
    }
    else
    {
        printf("%c", tree->data);
        preTree(tree->lchild);
        preTree(tree->rchild);
    }
}


char str[] = "A#BCD#E##F#G#H#I###";
int index1 = 0;

void createTree(BigTree* tree)
{
    char ch = str[index1];
    index1++;
    (*tree) = (BigTree)malloc(sizeof(Treenode));
    if(ch == '#' || ch == '\0')
    {
        (*tree) = NULL;
    }
    else 
    {
        
        (*tree)->data = ch;
        createTree(&((*tree)->lchild));
        createTree(&((*tree)->rchild));
    }
    
}



int main(int argc, char* argv[])
{

    BigTree tree = NULL;
    createTree(&tree);
    preTree(tree);
    printf("\n");
    return 0;
}