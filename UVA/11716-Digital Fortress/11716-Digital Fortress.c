#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long int T, i, j, c, p, L, r;
    double root;
    char str1[10005], str2[10005];

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        gets(str1);
        L = strlen(str1);
        root = sqrt(L);
        r = (int)root;

        if(root != (int)root)
            printf("INVALID\n");
        else
        {
            i=0, j=0, c=0, p=0;

            while(i<L)
            {
                if(p < L)
                {
                    str2[j] = str1[p];
                    ++j;
                }
                else
                {
                    p=c+1;
                    c=p;
                    str2[j] = str1[p];
                    ++j;
                }

                p += r;
                ++i;

            }

            str2[j] = '\0';

            puts(str2);
        }
    }

    return 0;
}
