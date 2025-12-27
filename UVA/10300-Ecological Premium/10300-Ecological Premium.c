#include<stdio.h>
int main()
{
    long int n,f,a,b,c,i,j,M;

    while(scanf("%ld", &n) == 1)
    {
        for(i=1; i<=n; i++)
        {
            M=0;
            scanf("%ld",&f);
            for(j=1; j <= f; j++)
            {
                scanf("%ld %ld %ld", &a, &b, &c);
                M += (a*c);
            }
            printf("%ld\n",M);
        }
    }

    return 0;
}
