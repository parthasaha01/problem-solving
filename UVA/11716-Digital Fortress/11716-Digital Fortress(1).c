#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long int T, i,c, p, L, r;
    double root;
    char str1[10005];

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        gets(str1);
        L = strlen(str1);
        root = sqrt(L);
        r = (int)root;

        if(root != (int)root)
            printf("INVALID");
        else
        {
            i=0, c=0, p=0;

            while(i<L)
            {
                if(p < L)
                    printf("%c",str1[p]);
                else
                {
                    p=c+1;
                    c=p;
                    printf("%c",str1[p]);
                }

                p += r;
                ++i;

            }
        }
        printf("\n");
    }

    return 0;
}
