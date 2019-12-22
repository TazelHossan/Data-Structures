#include<stdio.h>
//#include<windows.h>
int main()
{
    int N,K=1,LOC=1;

    double MAX,DATA[1000];
    printf("\n\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");
    printf("                        A Program To Find A Maximum\n");
    printf("                      Value And It\'s Respected Location\n");
    printf("                          From The Given Array\n");
    printf("     ==========================================================\n");
    printf("     ==========================================================\n");

    printf("\n\t\t Input The Size Of The Array ::");

    scanf("%d",&N);

    printf("\n\t\t Input The Elements Into The Array ::");

    for(K=1; K<=N; K++)
    {
        scanf("%lf",&DATA[K]);
    }

    MAX=DATA[1];
    for(K=1; K<=N; K++)
    {

        if(MAX<DATA[K])
        {
            MAX=DATA[K];

        }

    }

    printf("\n\t\t MAX Value:: %lf",MAX);
    printf("\n\t\t Index    :: ");


    for(K=1; K<=N; K++)
    {
        if(MAX == DATA[K])
        {
            LOC=K;
            printf("%d ",LOC);
        }
    }
    printf("\n\n\n");

    return 0;
}
