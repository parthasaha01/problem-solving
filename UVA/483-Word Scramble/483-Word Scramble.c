#include<stdio.h>
#include<string.h>
int main()
{
    long int i, j, k, x, L1;
    char str1[2000], str2[2000], str3[2000];

    while(gets(str1))
    {
        L1 = strlen(str1);

        j=0;
        x=0;

        for(i=0; i<L1; i++)
        {
            if(str1[i] != ' ')
            {
                str2[j] = str1[i];
                ++j;
            }
            else
            {
                str2[j] = '\0';

                for(k=0; k<j; k++)
                {
                    str3[x] = str2[j-k-1];
                    ++x;
                }

                str3[x] = str1[i];
                ++x;
                j=0;

            }
        }

        str2[j] = '\0';

        for(k=0; k<j; k++)
        {
            str3[x] = str2[j-k-1];
            ++x;
        }
        str3[x] = '\0';

        puts(str3);
    }

    return 0;
}
