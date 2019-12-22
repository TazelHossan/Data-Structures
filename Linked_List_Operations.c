#include<stdio.h>
#include<stdlib.h>
typedef struct mylist
{
    int data;
    struct mylist *next;
} node;

struct node
{
    int num;
    struct node * prev;
    struct node * next1;
}*stnode,*ennode;


void createList(int);
void displayListFromFirst();
void displayListFromEnd();


void createLinkList(head,data);
void displayLinkList(node* s);
void insertfirst(node *s,int data2);
int position(node *s,int data33);
void insertpos(node *s,int data3,int n1);
void deleteNode(node *s,int dell);
void Search(node *s,int search1);


struct node* emplist(struct node *start, int data);
int main()
{
    int data,del,data2,data3,number,i,data33, n1;

    node *head =( node*)malloc(sizeof(node));
    stnode =NULL;
    ennode =NULL;
    head->next=NULL;
    struct node *start = NULL;
    printf("\n\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n");
    printf("                >>>> A Program Of Linked List Operations <<<<\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n\n\n");



    printf("\n\n");
    printf("     ==============================================================\n");
    printf("                   >>>>> Enter Your Choice <<<<<\n");
    printf("     ==============================================================\n");
    printf("         || Press \"1\" for create a link list                ||\n");
    printf("         || Press \"2\" for Display the link list             ||\n");
    printf("         || Press \"3\" for insert an element on a first node ||\n");
    printf("         || Press \"4\" for insert an element on a given node ||\n");
    printf("         || Press \"5\" for Delete an element From the list   ||\n");
    printf("         || Press \"6\" for search an element on a link list  ||\n");
    printf("         || Press \"7\" for create a Doubly linked list       ||\n");
    printf("         || Press \"8\" for display The Doubly list from First||\n");
    printf("         || Press \"9\" for display The Doubly list from Last ||\n");
    printf("         || Press \"0\" for Exit                              ||\n");
    printf("     ==============================================================\n");
    printf("     ==============================================================\n");

     printf("\n\t\t Enter Your Choice::");
    while(1)
    {
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {


            printf("\n Insert The Elements On A Linked List(End With (-1))::  ");
            while(1)
            {

                scanf("%d",&data);
                if (data==-1)
                {
                    printf("\n\n\t Singly Linked List Created Successfully ::\n");
                    break;
                }

                createLinkList(head,data);
            }


        }

        if(ch==2)
        {
            printf("\n\n    ==================Displaying Data=================\n\n");
            displayLinkList(head);
        }


        if(ch==3)
        {
            int new_data1;
            printf("\n Enter A New Data::");
            scanf("%d",&new_data1);
            insertfirst(head,new_data1);

            printf("\n\n    ==================Insert An Element On A First Node==================\n\n");
            displayLinkList(head);
        }

        if(ch==4)
        {
            printf("\n\n    ==================Insert An Element After A Given Node=================\n\n");
            printf("\n Give A Node:: ");
            scanf("%d",&data33);
            printf("\n Enter A Inserted Element:: ");
            scanf("%d",&data3);
            n1=position(head,data33);
            insertpos(head,data3,n1);
            displayLinkList(head);

        }

        if(ch==5)
        {
            int item;
            printf("\n Eneter An Item Which Is To Be Deleted:: ");
            scanf("%d",&item);
            printf("\n\n    ==================After Deleting A Node=================\n\n");
            deleteNode(head,item);
            displayLinkList(head);
        }

        if(ch==6)
        {
            int x ;
            printf("\n Enter An Item Which Is To Be Found::");
            scanf("%d",&x);
            printf("\n\n");
            Search(head,x);
        }



        if(ch==7)
        {

            int n,nu;

            int choice;
            stnode = (struct node *)malloc(sizeof(struct node));

            if(stnode != NULL)
            {
                printf("\n Input Data For Node 1 (Stop With (-1)) :: ");
                scanf("%d", &nu);

                stnode->num = nu;
                stnode->prev = NULL;
                stnode->next1 = NULL;
                ennode = stnode;
            }
            int j=1;
            while(1)
            {
                j++;

                printf("\n Input Data For Node %d (Stop With (-1)) :: ",j);

                scanf("%d", &n);

                if(n==-1)
                {
                    printf("\n\n\t Doubly Linked List Created Successfully ::\n");
                    break;
                }

                createList(n);

            }
        }

        if(ch==8)
        {
            displayListFromFirst();
        }
        else if(ch==9)
        {
            displayListFromEnd();
        }

        if(ch==0)
        {
            exit(0);
        }
        getchar();

printf("\n\t\t Enter Another Choice::");

    }
    return 0;
}



void createLinkList(node*s,int data1)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*)malloc(sizeof(node));
    s->next->data=data1;
    s->next->next=NULL;
}

void displayLinkList(node* s)
{
    while(s->next!=NULL)
    {
        printf("\t %d ->",s->next->data);

        s=s->next;
    }
    printf(" NULL");
}



void insertfirst(node *s,int data2)
{
    node *n;
    n=(node*)malloc(sizeof(node));
    n->data=data2;
    n->next=s->next;
    s->next=n;
}
int position(node *s,int data33)
{

    int n11=0;

    while(s->next!=NULL)
    {
        n11++;
        if(s->next->data==data33)
        {
            break;
        }
        s=s->next;
    }
    return n11;
}
void insertpos(node *s,int data3,int n1)
{
    int c=0;
    while(s->next!=NULL)
    {
        if(c==n1)
        {
            break;
        }
        else
        {
            c++;
            s=s->next;
        }
    }
    node *n;
    n=(node*)malloc(sizeof(node));
    n->data=data3;
    n->next=s->next;
    s->next=n;
}






void Search(node *s,int search1)
{
    int c=0;
    while(s->next!=NULL)
    {
        if(s->next->data==search1)
        {
            c++;
        }
        s=s->next;
    }
    if(c==0)
        printf("\n\t %d Is Not Found\n",search1);
    else
        printf("\n\t Yes, %d Is Found\n",search1);
}

void deleteNode(node *s,int del1)
{
    while(s->next!=NULL)
    {
        if(s->next->data==del1)
        {
            s->next=s->next->next;
        }
        s=s->next;
    }
}



void createList(int n)
{
    struct node *newNode;


    newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode != NULL)
    {


        newNode->num = n;
        newNode->prev = ennode;
        newNode->next1 = NULL;

        ennode->next1 = newNode;
        ennode = newNode;
    }
}

void displayListFromFirst()
{
    struct node * temp;
    int n = 1;

    if(stnode == NULL)
    {
        printf("List Is Empty.");
    }
    else
    {
        temp = stnode;
        printf("\n\n    ==================Displaying Data Of Doubly Linked List=================\n\n");

        while(temp != NULL)
        {
            printf("\t %d ->",temp->num);
            n++;
            temp = temp->next1;
        }
        printf(" NULL\n");
    }
}

void displayListFromEnd()
{
    struct node * temp;
    int n = 0;

    if(ennode == NULL)
    {
        printf("\n\t List Is Empty.");
    }
    else
    {
        temp = ennode;
        printf("\n\n    ==================Displaying Data Of Doubly Linked List=================\n\n");

        while(temp != NULL)
        {
            printf("\t %d ->",temp->num);

            temp = temp->prev;
        }
        printf(" NULL\n");
    }
}
-
