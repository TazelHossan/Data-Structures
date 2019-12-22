#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cstdlib>
int n,arr[80];
void REPLACE(char*,int,int,char*);
char* INSERT(char*,int, char*);
char* DELETE(char*,int,int );
int INDEX(char*,char *);
void DEL(char*,int,int);
char* substring(char*, int, int);

int INDEX(char Text[],char pattern[])
{
    int i,j,index,flag;
    for(i=0; i<strlen(Text); i++)
    {
        index=i;
        flag=1;

        for(j=0; j<strlen(pattern); j++)
        {
            if(Text[i+j]==pattern[j])
                ;
            else
            {
                flag=0;
                break;
            }
        }

        if(flag==0)
        {
            continue;
        }
        else
            return (index);

    }
    if(i==strlen(Text))
        return -1;

}
void BubbleSort(int arr[],int n)
{
    int swap=0;
    for(int i=0 ; i<n; i++)
    {
        for(int j=0 ; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;

            }
        }
    }
}

int BinarySearch(int arr[],int item,int UB)
{
    int LB=0,mid;

    while(LB<=UB)
    {
        mid = (LB+UB)/2;
        if(item==arr[mid])
        {
            break;

        }
        if(item<arr[mid])
        {
            UB =mid -1;
        }
        else
        {
            LB =mid+1;
        }
    }

    if(LB>UB)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}


using namespace std;
int main()
{
    cout<< "\n\n";
    cout<< "        ==========================================================\n";
    cout<< "        ==========================================================\n";
    cout<< "                    A Program For Bubble Sort ,Binary Search\n";
    cout<< "                     And String Operations(DELETE,REPLACE)\n";
    cout<< "        ==========================================================\n";
    cout<< "        ==========================================================\n\n\n";


    cout<< "     ===================================================================\n";
    cout<< "                        Enter Your Choice\n";
    cout<< "     ===================================================================\n";
    cout<< "         || Press \"1\" For Bubble Sort                           ||\n";
    cout<< "         || Press \"2\" For Binary Searching                      ||\n";
    cout<< "         || Press \"3\" For Delete An Pattern From The Given Text ||\n";
    cout<< "         || Press \"4\" For Replace A Pattern From The Given Text ||\n";
    cout<< "         || Press \"5\" For Exiting From The Present Actions      ||\n";
    cout<< "     ===================================================================\n";
    cout<< "     ===================================================================\n";
    cout<< "\n\t\t Enter Your Choice :: ";

    while(1)
    {
        int choice;
        int UB;

        cin>>choice;
        getchar();

        if(choice==3)
        {

            char Text[1000],pattern[1000];
            int position,length,K;

            cout<<"\n\t\t Enter A Text ::";

            gets(Text);

            cout<<"\n\t\t Enter A Pattern ::";
            gets(pattern);

            K =INDEX(Text,pattern);
            while(K!=-1)
            {
                DEL(Text,K+1,strlen(pattern));
                K =INDEX(Text,pattern);
            }
            cout<< "     ======================================"<<endl;
            cout<< "            >>>> After Deletation <<<<"<<endl;
            cout<< "     ======================================"<<endl;
            cout<<"             "<<Text<<endl;

        }


        if(choice==4)
        {
            int K;
            char Text[10000], Pattern[10000],leters[1000];
            cout<<"\n\t\t Enter A Text ::";
            gets(Text);

            cout<<"\n\t\t Enter The Pattern ::";
            gets(Pattern);
            cout<<"\n\t\t Enter The Replaced Pattern::";
            gets(leters);
            K =INDEX(Text,Pattern)+1;
            while(K!=0)
            {
                REPLACE(Text,K,strlen(Pattern),leters);
                K =INDEX(Text,Pattern)+1;
            }
            cout<< "     ======================================"<<endl;
            cout<< "            >>>> After Replacement <<<<"<<endl;
            cout<< "     ======================================"<<endl;

            cout<<"             "<<Text<<endl;;

        }



        if(choice==1)
        {
            int i;
            cout<< "\n\t\t Input A Size Of The Array :: ";
            cin>>n;
            UB = n;
            cout<< "\n\t\t Input The Elements Into The Array ::  ";
            for(int i =0; i<n; i++)
            {
                cin>>arr[i];

            }

            BubbleSort(arr, UB);
            cout<< "     ======================================"<<endl;
            cout<< "              >>> After Sorting <<<" <<endl;
            cout<< "     ======================================"<<endl;
            cout<<"\t\t";
            for(int i =0; i<n; i++)
            {
                cout<<setw(4)<<arr[i]<< " " ;

            }
            cout<<endl;



        }


        if(choice==2)
        {
            int item;
            cout<< "\n\t\t Input An Item Which Is To Founded:: ";
            cin>>item;

            if(1==BinarySearch(arr,item,UB))
            {
                cout<< "\n\t\t Item Is Found !!!"<<endl;
            }
            if(0==BinarySearch(arr,item,UB))

            {
                cout<< "\n\t\t Item Is Not Found !!!"<<endl;
            }
        }

        if(choice==5)
        {
            exit(0);
        }

        cout<< "\n\t\t Enter Another Choice :: ";

    } //end while

    return 0;
}
char *substring(char *string, int position, int length)
{
    char *ptr;
    int i=0;
    ptr = (char*)malloc(5*sizeof(length)); //this line is important
    while (i<length)

    {
        ptr[i] = string[position-1+i];

        i++;
    }
    ptr[i]='\0';


    return ptr;
}
void DEL(char* S1,int K,int L)
{
    char *ptr1, *ptr2;
    ptr1 = substring(S1, 1, K - 1 );
    ptr2 = substring(S1, K+L, strlen(S1)-K-L+1);
    strcpy(S1, "");
    strcat(S1,ptr1);
    strcat(S1,ptr2);

}

char* DELETE(char* S1,int K,int L)
{
    char *ptr1, *ptr2;
    ptr1=(char*)malloc(4*sizeof(L));
    ptr2=(char*)malloc(4*sizeof(L));
    ptr1 = substring(S1, 1, K - 1 );
    ptr2 = substring(S1, K+L, strlen(S1)-K-L+1);
    strcpy(S1, "");
    strcat(S1,ptr1);
    strcat(S1,ptr2);
    return S1;
}

char* INSERT(char *S1,int K, char *S2 )
{
    char *ptr1, *ptr2;
    ptr1=(char*)malloc(4*sizeof(int));
    ptr2=(char*)malloc(4*sizeof(int));
    ptr1 = substring(S1, 1, K - 1 );
    ptr2 = substring(S1, K, strlen(S1)-K+1);
    strcpy(S1, "" );
    strcat(S1,ptr1);
    strcat(S1,S2);
    strcat(S1,ptr2);
    return S1;
}

void REPLACE(char* S1,int p,int l, char* S3)
{
    char *ptr1, *ptr2;

    ptr1=(char*)malloc(4*sizeof(int));
    ptr2=(char*)malloc(4*sizeof(int));
    ptr1=DELETE(S1,p,l);
    ptr2=INSERT(ptr1,p,S3);

}



