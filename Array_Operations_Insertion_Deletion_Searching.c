#include<stdio.h>
int main()
{
    int n, arr[100],i,j,choice,position,new_element,item,loc=0,temp=0,arr2[200];

    printf("\n\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n");
    printf("                 >>>> A Program Of Array Operations <<<<\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n\n\n");



    printf("\n\n");
    printf("     ===================================================================\n");
    printf("                      >>>> Enter Your Choice <<<<\n");
    printf("     ===================================================================\n");
    printf("         || Press \"1\" For Insert The Data Elements Into The Array||\n");
    printf("         || Press \"2\" For Displaying The Inserted Elements       ||\n");
    printf("         || Press \"3\" For Insert An Element To The Array         ||\n");
    printf("         || Press \"4\" For Delete An Element From The Array       ||\n");
    printf("         || Press \"5\" For Search An Element From The Array       ||\n");
    printf("         || Press \"6\" For Exiting From The Present Actions       ||\n");
    printf("     ===================================================================\n");
    printf("     ===================================================================\n");

    printf("\n\t\t Enter Your Choice::");

    while(1)
    {

        scanf("%d",&choice);
        if(choice==1)

        {
            printf("\n\t\t Enter The Size Of The \"DATA\" Array::");
            scanf("%d",&n);
            printf("\n\t\t Insert The Elements Into The \"DATA\" Array::");

            for(i=0; i<n; i++)
            {
                scanf("%d",&arr[i]);
            }
        }




        if(choice==2)
        {
            printf("     ===================================================================\n");
            printf("                  Displaying The Inserted Elements \n");
            printf("     ===================================================================\n");

            for(i=0; i<n; i++)
            {
                printf("\t%d ",arr[i]);
            }

        }


        if(choice==3)
        {
            printf("\n\t\t Input A Position Where Is Insert A New Data Element::");

            scanf("%d",&position);

            printf("\n\t\t Input The New Data::");

            scanf("%d",&new_element);

            for(i=0; i<n; i++)
            {
                if(i==position)
                {
                    for(j=n; j>=position; j--)
                    {

                        arr[j] = arr[j-1];

                    }
                    arr[i]=new_element;
                }
            }
            printf("     ===================================================================\n");
            printf("                  Displaying The All Data Elements \n");
            printf("     ===================================================================\n");
            for(i=0; i<n+1; i++)
            {
                printf("\t%d ",arr[i]);
            }

        }

        if(choice==4)
        {
            printf("\n\t\t Input A Position In Which Data Is To Be Deleted::");

            scanf("%d",&position);

            for(i=0; i<n; i++)
            {
                if(i==position)
                {
                    for(j=position; j<n; j++)
                    {

                        arr[j] = arr[j+1];

                    }

                }
            }

            printf("     ===================================================================\n");
            printf("                  Displaying The All Data Elements \n");
            printf("     ===================================================================\n");
            for(i=0; i<n-1; i++)
            {
                printf("\t%d ",arr[i]);
            }

        }


        if(choice==5)
        {
            printf("\n\t\t Input An Item which Is To Be Founded::");


            scanf("%d",&item);



            for(i=0; i<n; i++)
            {
                if(arr[i]==item)
                {
                    printf("\n\t\t Item %d Is Founded.\n",item);
                    printf("\n\t\t Location Is ::");
                    printf("%d ",i+1);
                    break;

                }
            }
            if(arr[i]!=item)
            {
                printf("\n\t\t Item %d Is Not Found!\n",item);
            }


        }

        if(choice==6)
        {
            exit(0);
        }

        printf("\n\t\t Enter Another Choice::");


    }

    return 0;
}
