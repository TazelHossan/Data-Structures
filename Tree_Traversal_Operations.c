#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    scanf("%d",&x);

    if(x==-1)
        return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("\n\t Enter The Left Child Of %d::(-1 For No Entry)::",x);
    p->left=create();
    printf("\n\t Enter The Right Child Of %d::(-1 For No Entry)::",x);
    p->right=create();
    return p;
}

void postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("\t%d->",t->data);
    }
}
void preorder(node *t)
{
    if(t!=NULL)
    {
        printf("\t%d->",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("\t%d->",t->data);
        inorder(t->right);
    }
}
void main()
{
    node *root;
    int ch;
     printf("\n\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n");
    printf("               >>>> A Program Of Tree Traversal Operations <<<<\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n\n\n");

    printf("\n\n");
    printf("     ==========================================================\n");
    printf("                   >>>>> Enter Your Choice <<<<<\n");
    printf("     ==========================================================\n");
    printf("         || Press \"1\" For Create A Tree                    ||\n");
    printf("         || Press \"2\" For Pre-Order Of The Tree            ||\n");
    printf("         || Press \"3\" For Post-Order Of The Tree           ||\n");
    printf("         || Press \"4\" For In-Order Of The Tree             ||\n");
    printf("         || Press \"5\" For Exiting From The Present Actions ||\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");
    printf("\n\t Enter Your choice::");
    while(1)
    {

        scanf("%d",&ch);

        if(ch==1)
        {
            printf("\n\t Enter The Root::");
            root=create();
            printf("\n\t The Tree Is Created Successfully .\n");

        }
        if(ch==2)
        {
            printf("\n            The Pre-Order Traversal Of Tree Is::\n ");
            printf("     ==========================================================\n");
            preorder(root);
            printf(" NULL\n");
            printf("     ==========================================================\n");
            printf("\n");

        }
        if(ch==3)
        {
            printf("\n            The In-Order Traversal Of Tree Is::\n ");
            printf("     ==========================================================\n");
            inorder(root);
            printf(" NULL\n");
            printf("     ==========================================================\n");
            printf("\n");
        }
        if(ch==4)
        {
            printf("\n            The Post-Order Traversal Of Tree Is::\n ");
            printf("     ==========================================================\n");
            postorder(root);
            printf(" NULL\n");
            printf("     ==========================================================\n");
            printf("\n");

        }

        if(ch==5)
        {
            exit(0);
        }
        printf("\n\t Enter Another Choice::");
    }
    return 0;
}
