#include<stdio.h>
int main()
{
    int DATA[100], LOC1 =1, LOC2 = 2, N,K,i,FIRST,SECOND,SWAP1,SWAP2;
     printf("\n\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");
    printf("                        A Program Of Searching\n");
    printf("                    First And Second Largest Number\n");
    printf("                      And There Respected Locations\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");

    printf("\n\t\t Input A Size Of \"DATA\" Array ::");

    scanf("%d",&N);
    printf("\n\t\t Inserted The Elements To The \"DATA\" Array ::");
    for(i=1 ; i<=N; i++)
    {
        scanf("%d",&DATA[i]);
    }


    FIRST = DATA[1];
    SECOND = DATA[2];

    if( FIRST < SECOND)
    {
        SWAP1 = FIRST ;
        FIRST = SECOND;
        SECOND =SWAP1 ;
        SWAP2 = LOC1 ;
        LOC1 = LOC2 ;
        LOC2 = SWAP2;
    }

    for(K =3 ; K<=N ; K++)
    {
        if(FIRST < DATA[K])
        {
            SECOND = FIRST ;
            FIRST = DATA[K];
            LOC2 = LOC1 ;
            LOC1 = K ;
        }

        else if(SECOND < DATA[K])
        {
            SECOND = DATA[K];
            LOC2 = K ;

        }

    }

    printf("\n\t\t Largest Number Is::%d ,it\'s Location is::%d\n",FIRST,LOC1) ;
    printf("\n\t\t Second Largest Number Is::%d ,it\'s Location Is::%d\n",SECOND,LOC2);



    return 0;
}
