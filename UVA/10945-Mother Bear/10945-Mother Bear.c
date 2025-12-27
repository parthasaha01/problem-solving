#include<stdio.h>
#include<string.h>
int main()
{
    long int i, j, k;
    char str1[5000], str2[5000], str3[5000];

    while(gets(str1))
    {

        if(strcmp(str1, "DONE") == 0)
            break;

        j=0;

        for(i=0; str1[i] != '\0'; i++)
        {
            if( str1[i] >= 'a' && str1[i] <= 'z' )
            {
                str2[j] = str1[i];
                ++j;
            }
            else if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str2[j] = str1[i]+32;
                ++j;
            }
        }

        str2[j] = '\0';

        k=0;

        for(i=j-1; i>=0; i--)
        {
            str3[k] = str2[i];
            ++k;
        }

        str3[k] = '\0';

        if(strcmp(str2, str3) == 0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }

    return 0;
}
