#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define MAX 80
#define MAX1 80
#define MAX2 80
void quicksort(int array[25], int first, int last);
void insert();
void delete();
void displayQue();
int queue_array[MAX2];
int rear = - 1;
int front = - 1;
int Fibonacci(int);
int top=-1;
int top1=-1;
int stack[MAX];
int stack1[MAX1];
void Tower(int,char,char,char);
int priority(char x);
void push();
void push1(char x);
char pop1();
void pop();
void display();
int factorial(int);
int main()
{
    int ch ;
    printf("\n\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n");
    printf("               >>>> A Program Of Stack And Queue Operations <<<<\n");
    printf("                       And Infix To Postfix Conversion\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n\n\n");

    printf("\n\n");
    printf("     ==============================================================\n");
    printf("                   >>>> Enter Your Choice <<<<\n");
    printf("     ==============================================================\n");
    printf("         || Press \"1\"  For Push                             ||\n");
    printf("         || Press \"2\"  For Pop                              ||\n");
    printf("         || Press \"3\"  For Display                          ||\n");
    printf("         || Press \"4\"  For Insert Element To Queue          ||\n");
    printf("         || Press \"5\"  For Delete Element From Queue        ||\n");
    printf("         || Press \"6\"  For Display All Elements Of Queue    ||\n");
    printf("         || Press \"7\"  For Tower Of Hanoii                  ||\n");
    printf("         || Press \"8\"  For Factorial                        ||\n");
    printf("         || Press \"9\"  For Fibonaccii                       ||\n");
    printf("         || Press \"10\" For Infix To Postfix                 ||\n");
    printf("         || Press \"11\" For Quicksort                       ||\n");
    printf("         || Press \"0\" For Exiting From The Present Actions  ||\n");
    printf("     ==============================================================\n");
    printf("     ==============================================================\n");

    printf("\n Enter Your Choice::");
    while(1)
    {


        scanf("%d",&ch);
        {
            if(ch==1)
            {
                push();
            }
            if(ch==2)
            {
                pop();
            }
            if(ch==3)
            {
                display();
            }
            if(ch==7)
            {
                int n,move;
                printf("\n Enter The Number Of Disks ::");
                scanf("%d",&n);
                printf("\n\n");
                Tower(n, 'A', 'B', 'C' );
                move=pow(2,n)-1;
                printf(" ||-----------------------------------||\n");
                printf(" ||   Total Number Of Moveds ::%d     ||\n",move);
                printf(" ||-----------------------------------||\n");
            }
            if(ch==8)
            {
                int n,fact ;
                printf("\n Enter A Number::");
                scanf("%d",&n);
                fact=factorial(n);
                printf("\n The Factorial Of %d! Is = %d",n,fact);

            }
            if(ch==9)
            {
                int num, i = 0, c;
                printf("\n Enter A Number ::");
                scanf("%d",&num);

                printf("\n Fibonacci Series ::\n");

                for ( c = 1 ; c <= num ; c++ )
                {
                    printf(" \t%d ", Fibonacci(i));
                    i++;
                }
                printf("\n");
            }

             if(ch == 11)
            {
                int j, size, array[25];

                printf("\n\t Enter the size of the array :: ");
                scanf("%d", &size);

                printf("\n\t insert the elements into the array ::", size);
                for(j = 0; j < size; j++)
                    scanf("%d", &array[j]);

                quicksort(array, 0, size - 1);

                printf("\n\t The sorted elements are ::");
                printf("\n-----------------------------------\n");
                for(j = 0; j < size; j++)
                    printf("\t%d", array[j]);
            }



            if(ch==10)
            {
                char exp[20];
                char *e, x;
                printf("\n Enter The Infix Expression :: ");
                scanf("%s",exp);
                printf("\n Postfix is::");
                e = exp;
                while(*e != '\0')
                {
                    if(isalnum(*e))
                        printf("%c",*e);
                    else if(*e == '(')
                        push1(*e);
                    else if(*e == ')')
                    {
                        while((x = pop1()) != '(')
                            printf("%c", x);
                    }
                    else
                    {
                        while(priority(stack1[top1]) >= priority(*e))
                            printf("%c",pop1());
                        push1(*e);
                    }
                    e++;
                }
                while(top1!= -1)
                {

                    printf("%c",pop1());
                }
            }
            if(ch==4)
            {
                insert();
            }
            if(ch==5)
            {
                delete();
            }
            if(ch==6)
            {
                displayQue();
            }
            if(ch==0)
            {
                exit(0);
            }

        }
        printf("\n\t Enter Another Choice::");
    }

    return 0;
}

void Tower(int n, char A, char B, char C)
{
    if(n==1)
    {
        printf("\n Move From Tower %c to Tower %c\n",A,C);
    }
    else
    {
        Tower(n-1,A, C,B);
        Tower(1,A,B,C);
        Tower(n-1,B,A,C);
    }
}
void push()
{
    int val;

    if(top==MAX-1)
    {
        printf("\n Stack Is Full !");
    }
    else
    {
        printf("\n Enter Element To Push:");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\n Stack Is Empty !");
    }
    else
    {
        printf("\n Deleted Element Is :: %d",stack[top]);
        top=top-1;
    }
}

void display()
{
    int i;

    if(top==-1)
    {
        printf("\n Stack Is Empty!!");
    }
    else
    {
        printf("\n Stack Is:: ");
        for(i=top; i>=0; --i)
        {
            printf("\t%d ",stack[i]);
        }
        printf("\n\n");

    }
}

int factorial(int n)
{
    int fact=0;
    if(n<0)
        return -1;
    if(n==0)
        return 1;
    else
        return fact=n*factorial(n-1);

}


int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void push1(char x)
{
    stack1[++top1] = x;
}

char pop1()
{
    if(top1 == -1)
        return -1;
    else
        return stack1[top1--];
}



void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("\n Queue Overflow ! \n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("\n Inset The Element In Queue :: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("\n Queue Underflow ! \n");
        return ;
    }
    else
    {
        printf("\n Element Deleted From Queue Is :: %d", queue_array[front]);
        front = front + 1;
    }
}

void displayQue()
{
    int i;
    if (front == - 1)
        printf("\n Queue Is Empty ! \n");
    else
    {
        printf("\n Queue Is :: ");
        for (i = front; i <= rear; i++)
            printf("\t%d ", queue_array[i]);
        printf("\n");
    }
}



int Fibonacci(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( Fibonacci(n-1) + Fibonacci(n-2) );
}

void quicksort(int array[25], int first, int last)
{
    int i, j, pivot, temp;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(array[i] <= array[pivot] && i < last)
                i++;
            while(array[j] > array[pivot])
                j--;
            if(i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quicksort(array, first, j - 1);
        quicksort(array, j + 1, last);

    }
}

