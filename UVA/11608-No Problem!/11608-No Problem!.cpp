#include<cstdio>
using namespace std;
int main()
{
    int S, a[12], b[12], i, test=1;

    while(scanf("%d", &S)==1 && S>=0)
    {
        for(i=0; i<12; i++)
            scanf("%d", &a[i]);

        for(i=0; i<12; i++)
            scanf("%d", &b[i]);

        printf("Case %d:\n", test++);

        for(i=0; i<12; i++)
        {
            if(b[i] <= S)
            {
                printf("No problem! :D\n");
                S -= b[i];
            }
            else
            {
                printf("No problem. :(\n");
            }

            S += a[i];
        }

    }

    return 0;
}
