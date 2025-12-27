 #include<stdio.h>
int main()
{
    long long  Z, I, M, L, COUNT, test=0,i, k, seed, a[10000];

    while(scanf("%lld %lld %lld %lld", &Z, &I, &M, &L) == 4)
    {
        if(Z == 0 && I == 0 && M == 0 && L == 0)
            break;

        long long ara[10000] = {0};
        COUNT = 0;
        i=0;
        k=0;

        while(ara[L] != 1)
        {
            ara[L] = 1;

            L = (Z*L+I)%M;

            ara[k++] = L;

            COUNT++;

        }
        if(ara[0] == ara[k-1] && COUNT != 1)
            --COUNT;

        printf("Case %lld: %lld\n", ++test, COUNT);
    }

    return 0;
}
