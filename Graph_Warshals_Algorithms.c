#include<stdio.h>
#include<stdlib.h>
#define LIMIT 100
#define INF 99999
void show(int mat[LIMIT][LIMIT], int n);
void new_graph();
int adjacency_matrix[LIMIT][LIMIT];
int n;
struct Graph
{
    int V; ///vertex
    int E; /// Edges
    int *Adj
};
void printfSolution(struct Graph *G)
{
    int I, J;
    for(I =0 ; I<G->V; I++)
    {
        for(J=0; J<G->E; J++)
        {
            if(*(G->Adj + I*(G->V)+J)==INF)
            {
                printf("%7s", "INF");
            }
            else
            {
                printf("%7d",*(G->Adj + I*(G->V)+J));
            }

        }
        printf("\n");
    }
}
void FloydWarshall(struct Graph* G)
{
    int I, J,K;
    int Dist[G->V][G->V];
    for(I =0; I< G->V; I++)
    {
        for(J =0 ; J< G->V; J++)
        {
            Dist[I][J]=*(G->Adj + I*(G->V)+J);
        }
    }

    for(K =0 ; K< G->V; K++)
    {
        for(I=0; I< G->V; I++)
        {
            for( J=0; J< G->V; J++)
            {
                if(Dist[I][K] + Dist[K][J] < Dist[I][J])
                {
                    Dist[I][J]= Dist[I][K] + Dist[K][J];
                }
            }
        }

    }
    for(I =0 ; I< G->V ; I++)
    {
        for(J=0; J< G->V; J++)
        {
            *(G->Adj + I*G->V +J)= Dist[I][J];
        }
    }
}
int main()
{
     printf("\n\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n");
    printf("               >>>> A Program Of Warshal\'s Algorithms <<<<\n");
    printf("       ============================================================\n");
    printf("       ============================================================\n\n\n");

     printf("\n\n");
    printf("     =============================================================\n");
    printf("                   >>>>>Enter Your Choice<<<<<\n");
    printf("     =============================================================\n");
    printf("         || Press \"1\" For Displaying The Matrix            ||\n");
    printf("         || Press \"2\" For Displaying The Shortest Distance ||\n");
    printf("         || Press \"3\" For Displaying The Path Matrix       ||\n");
    printf("         || Press \"4\" For Exiting From The Present Actions ||\n");
    printf("     =============================================================\n");
    printf("     =============================================================\n");
    printf("\n\t Enter your choice::");

    struct Graph* G;
    int I,J;
    int matrix[4][4] =
    {
        {7,5,INF,INF},
        {7,INF,INF,2},
        {INF,3,INF,INF},
        {4,INF,1,INF}
    };

    G = (struct Graph*)malloc(sizeof(struct Graph));
    G->V = 4;
    G->E = 4;
    G->Adj = malloc((G->V)*(G->V)*sizeof(int));

    for(I = 0; I <G->V; I++)
    {
        for(J = 0; J< G->V; J++)
        {
            *(G->Adj + I*G->V +J)= matrix[I][J];
        }
    }
    int ch;


    while(1)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\n\t Original Distance::\n");
            printf("     ========================\n");
            printfSolution(G);
        }

    if(ch==2)
    {
        FloydWarshall(G);
        printf("\n\t Shortest Distance::\n");
        printf("     =============================\n");
        printfSolution(G);
    }
    if(ch==3)
    {
        int P[LIMIT][LIMIT];
        int i, j, k;
        new_graph();
        printf("\n============================\n");
        printf("     :Adjacency Matrix:\n");
        printf("============================\n");
        show(adjacency_matrix, n);
        printf("============================\n");
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                P[i][j] = adjacency_matrix[i][j];
            }
        }
        for(k = 0; k < n; k++)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    P[i][j] = (P[i][j] || (P[i][k] && P[k][j]));
                }
            }
            printf("============================\n");
            printf("A%d Is: \n", k);
            printf("============================\n");

            show(P, n);
        }
        printf("A%d Is The Path Matrix Of The Given Graph.\n", k - 1);
    }
    if(ch==4)
    {
        exit(0);
    }
    printf("\n\t Enter Another Choice::");

}    return 0;
}


void show(int mat[LIMIT][LIMIT], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void new_graph()
{
    int count, maximum_edges, origin, destination;
    printf("\n\t Enter Total Number of Vertices::");
    scanf("%d", &n);
    maximum_edges = n * (n - 1);
    for(count = 1; count <= maximum_edges; count++)
    {
        printf("\n Co-Ordinates of The Matrix(I,J). %d [(-1 -1) To Quit]::", count);
        scanf("%d %d", &origin,&destination);
        if((origin == -1) && (destination == -1))
        {
            break;
        }
        if(destination >= n ||  origin < 0 || origin >= n || destination < 0)
        {
            printf("\n\t Invalid Edge Input !\n");
            count--;
        }
        else
        {
            adjacency_matrix[origin][destination] = 1;
        }
    }
}

