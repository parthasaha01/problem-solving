#include<stdio.h>
int main()
{
    long long T, G, L;

    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld %lld",&G,&L);

        if(L%G == 0)
            printf("%lld %lld\n",G,L);
        else
            printf("-1\n");
    }

    return 0;
}
