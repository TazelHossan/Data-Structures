#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int choice;
    printf("\n\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n");
    printf("                  >>>> A Program Of String Operations <<<<\n");
    printf("        ==========================================================\n");
    printf("        ==========================================================\n\n\n");

    printf("\n\n");
    printf("     ===================================================================\n");
    printf("                        >>>> Enter Your Choice <<<<\n");
    printf("     ===================================================================\n");
    printf("         || Press \"1\" For Concatenation Of Two Given Strings       ||\n");
    printf("         || Press \"2\" For Displaying A Given String Leangth        ||\n");
    printf("         || Press \"3\" For Printing A Sub String From The Given Text||\n");
    printf("         || Press \"4\" For Indexing From The Given Text             ||\n");
    printf("         || Press \"5\" For Exiting From The Present Actions         ||\n");
    printf("     ===================================================================\n");
    printf("     ===================================================================\n");

    printf("\n\t\t Enter Your Choice::");
    while(1)

    {

        scanf("%d",&choice);

        if(choice ==1)
        {
            getchar();
            char str1[1000], str2[1000];
            int i, j;
            printf("\n\t Write The First String ::");
            scanf("%[^\n]%*c", str1);
            //scanf("%s", str1);
            printf("\n\t Write The Second String::");
            scanf("%[^\n]%*c", str2);
            //scanf("%s", str2);
            printf("\n\t\t -----------------------------------\n");
            printf("\n\t\t Concatenation of \"%s\" && \"%s\" :", str1, str2);
            printf("\n\t\t -----------------------------------\n");
            for(j = 0; str1[j] != '\0'; j++)
                ;
            for(i = 0; str2[i] != '\0'; i++, j++)
            {
                str1[j] = str2[i];
            }
            str1[j] = '\0';

            printf("\n\t\t %s\n", str1);
            printf("\n\t\t -----------------------------------");

        }


        if(choice == 2)
        {
            getchar();
            char str[100];
            int k, length;
            printf("\n\t\t Write A Text::");
            scanf("%[^\n]%*c", str);
            //scanf("%s", str);
            length =  stringLength(str);
            printf("\n\t\t ----------------------------------");
            printf("\n\t\t   : The String Length is :: %d", length);
            printf("\n\t\t ----------------------------------");

        }


        if(choice == 3)
        {
            getchar();
            char string[100];
            char sub_string[100];

            int position, length;

            printf("\n\t\t Write A String ::");

            scanf("%[^\n]%*c", string);
            // gets(string);

            printf("\n\t\t Enter The Position Of The Sub String ::");
            scanf("%d", &position);
            printf("\n\t\t Enter The Length Of The Sub String   ::");

            scanf("%d", &length);

            SubString(string, sub_string, position, length);
            printf("\n\t\t ----------------------------------");

            printf("\n\t\t : SUBSTRING(%s, %d ,%d): %s", string, position, length + 1, sub_string);
            printf("\n\t\t ----------------------------------");

        }


        if(choice == 4)
        {
            getchar();
            char Text[100], pattern[100];

            printf("\n\t\t Write A Text ::");
            scanf("%[^\n]%*c", Text);
            //scanf("%s", Text);

            printf("\n\t\t Write A Pattern::");
            scanf("%s", pattern);
            scanf("%[^\n]%*c", pattern);
            //gets(pattern);
            printf("\n\t\t ----------------------------------\n");
            printf("\n\t\t :  INDEX( '%s' ,'%s') = %d  :", Text, pattern, INDEX(Text, pattern));
            printf("\n\t\t ----------------------------------\n");

        }
        if(choice == 5)
        {
            exit(0);
        }

        printf("\n\t\t Enter Another choice::");

    }
    return 0;
}

int stringLength(char str[])
{
    int i = 0, count = 0;
    while(str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}
void SubString(char s[], char sub[], int p, int l)
{
    int i = 0;
    while (i < l)

    {
        sub[i] = s[p - 1 + i];

        i++;
    }
    sub[i] = '\0';
}

int INDEX(char Text[], char pattern[])
{
    int i, j, index, flag;
    for(i = 0; i < strlen(Text); i++)
    {
        index = i;
        flag = 1;

        for(j = 0; j < strlen(pattern); j++)
        {
            if(Text[i + j] == pattern[j])
                ;
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag == 0)
        {
            continue;
        }
        else
            return (index + 1);

    }
    if(i == strlen(Text))
        return -1;

}
