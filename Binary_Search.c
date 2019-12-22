#include<stdio.h>
int main()
{
    int DATA[100],BEG, LB=0,END,UB,MID,ITEM,LOC,I,N;
    printf("\n\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");
    printf("                        A Program Of Binary Search\n");
    printf("      NOTE::Insert The Values Into The Array In Ascending Order\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");

    printf("\n\t\t Enter A Size Of The \"DATA\" Array ::");

    scanf("%d",&N);

    BEG = LB;
    END = UB = N ;

    printf("\n\t\t Inserted The Elements As \"Ascending Order\" ::");

    for( I= 0 ; I<N ; I ++)

    {
        scanf("%x",&DATA[I]);

    }

    printf("\n\t\t Input A Value Which Is To Be Founded::");

    scanf("%x",&ITEM);


    while( BEG<= END)

    {
        MID = (BEG + END)/2;

        if(DATA[MID] == ITEM)
        {

            break ;
        }
        if(DATA[MID]>ITEM)
        {
            END = MID -1;
        }
        else
        {
            BEG = MID + 1;
        }
    }
    if(BEG > END)
    {
        printf("\n\t\t Entered Value \"%x\" Is Not Found !!! \n",ITEM);
    }

    else
    {
        printf("\n\t\t Entered Value \"%x\" Is Found In The \"DATA\" Array. \n",ITEM);
    }
    printf("\n\t\t And It\'s Locations :: ");


    for(I=0 ; I<N ; I++)
    {
        if(DATA[I] == ITEM)
        {
            LOC = I+1;
            printf("%d ",LOC);
        }
    }
    printf("\n\n");


    return 0;
}

