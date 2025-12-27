#include<cstdio>
int main()
{
    int T, N, a[10], i, test=1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d", &N);

        for(i=0; i<N; i++)
            scanf("%d", &a[i]);

        printf("Case %d: %d\n", test++, a[N/2]);
    }

    return 0;
}
