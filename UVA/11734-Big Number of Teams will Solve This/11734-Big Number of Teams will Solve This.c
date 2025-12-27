#include<stdio.h>
#include<string.h>
int main()
{
    long int T, i=0, j, k;

    char str1[25], str2[25], str3[25];

    scanf("%ld", &T);

    getchar();

    while(T--)
    {
        gets(str1);

        gets(str2);

        if(strcmp(str1, str2) == 0)
            printf("Case %ld: Yes\n", ++i);
        else
        {
            k=0;

            for(j=0; str1[j]; j++)
            {
                if(str1[j] != ' ')
                    str3[k++] = str1[j];
            }
            str3[k] = '\0';

            if(strcmp(str2, str3))
                printf("Case %ld: Wrong Answer\n", ++i);
            else
                printf("Case %ld: Output Format Error\n", ++i);
        }
    }

    return 0;
}
