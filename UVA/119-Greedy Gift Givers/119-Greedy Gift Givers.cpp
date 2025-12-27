#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int N, i, taka, P, per, j, k, x, flag=0;
    char str[12][15], name[15], man[15];

    while(scanf("%d", &N)==1)
    {

        int a[10] = {0};

        for(i=0; i<N; i++)
        {
            scanf("%s", str[i]);
        }

        for(i=0; i<N; i++)
        {
            scanf("%s %d %d", name, &taka, &P);

            if(P)
            {
                for(j=0; j<N; j++)
                {
                    if(!strcmp(str[j], name))
                    {
                        a[j] -= (taka-(taka%P));
                        break;
                    }
                }

                per = taka/P;

                for(k=0; k<P; k++)
                {

                    scanf("%s", man);

                    for(x=0; x<N; x++)
                    {
                        if(!strcmp(str[x], man))
                        {
                            a[x] += per;
                        }
                    }
                }
            }

        }

        if(flag)
            printf("\n");

        flag=1;

        for(i=0; i<N; i++)
        {
            printf("%s %d\n", str[i], a[i]);
        }
    }

    return 0;
}
