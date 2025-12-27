#include<stdio.h>
int main()
{
    long int T, N, i, mile, juice, test=1, num, p, q;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        mile=0;
        juice=0;

        for(i=0; i<N; i++)
        {
            scanf("%ld", &num);

            p=(num/30)+1;
            q=(num/60)+1;

            mile += (p*10);
            juice += (q*15);
        }

        if(mile < juice)
            printf("Case %ld: Mile %ld\n", test++, mile);
        else if(juice < mile)
            printf("Case %ld: Juice %ld\n", test++, juice);
        else
            printf("Case %ld: Mile Juice %ld\n", test++, mile);
    }

    return 0;
}
