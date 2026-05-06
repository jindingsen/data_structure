#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct treenode
{
    Elemtype data;
    struct treenode *lchild;
    struct treenode *rchild;
} Treenode;

typedef Treenode *Bigtree;

void preTree(Bigtree tree)
{
    if (tree == NULL)
    {
        return;
    }

    printf("%c ", tree->data);
    preTree(tree->lchild);
    preTree(tree->rchild);
}

void midTree(Bigtree tree)
{
    if (tree == NULL)
    {
        return;
    }

    midTree(tree->lchild);
    printf("%c ", tree->data);
    midTree(tree->rchild);
}

void postTree(Bigtree tree)
{
    if (tree == NULL)
    {
        return;
    }

    postTree(tree->lchild);
    postTree(tree->rchild);
    printf("%c ", tree->data);
}

void destroyTree(Bigtree tree)
{
    if (tree == NULL)
    {
        return;
    }

    destroyTree(tree->lchild);
    destroyTree(tree->rchild);
    free(tree);
}

char str[] = "AB#C##D##";
int idx = 0;

/* void createTree(Bigtree *tree)
{
    Elemtype ch = str[idx++];

    if (ch == '\0' || ch == '#')
    {
        *tree = NULL;
        return;
    }

    *tree = malloc(sizeof(Treenode));
    if (*tree == NULL)
    {
        return;
    }

    (*tree)->data = ch;
    (*tree)->lchild = NULL;
    (*tree)->rchild = NULL;

    createTree(&((*tree)->lchild));
    createTree(&((*tree)->rchild));
} */








int main(void)
{
    Bigtree tree = NULL;

    createTree(&tree);

    printf("preorder: ");
    preTree(tree);
    printf("\n");

    printf("inorder: ");
    midTree(tree);
    printf("\n");

    printf("postorder: ");
    postTree(tree);
    printf("\n");

    destroyTree(tree);
    return 0;
}
