#include <stdio.h>
#include <stdlib.h>

struct link
{
     int id;
     struct link *left;
     struct link *right;
};
typedef struct link *node;

int dem=0;
node makeNode(node p, int x)
{
    p = (node) malloc(sizeof(struct link));
    p->id = x;
    p->left = p->right = NULL;
    return p;
}
node  CreateTree(node p,int x)
{
    printf("Node: ");
    scanf("%d",&x);
    if (x==0)return NULL;
    p=  makeNode(p,x);
    printf("Con trai cua node %d la: ",x);
    p->left=CreateTree(p->left,x);
    printf("Con phai cua node %d la: ",x);
    p->right=CreateTree(p->right,x);
    return p;
}

void NLR(node root)
{
    if (root)
    {
        printf("%d",root->id);
        NLR(root->left);
        NLR(root->right);
    }
}

void Leaf(node root)
{

    if (root)
    {
        if((root->left==NULL)&&(root->right==NULL)){
            ++dem;
        }
        Leaf(root->left);
        Leaf(root->right);
    }
}
void DestroyTree(node root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        root = NULL;
    }
}

int main()
{
    node T=NULL;
    node p;
    int x;
    T=CreateTree(p,x);
    NLR(T);
    Leaf(T);
    printf("so la la : %d",dem);
}
