#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    long long N, M, i, result, n, m;

    while(scanf("%lld %lld", &N, &M) == 2)
    {
        if(N==0 && M==0)
            break;

        map<long int,int>jack;

        result = 0;

        for(i=0; i<N; i++)
        {
            scanf("%lld", &n);
            jack[n]=1;
        }
        for(i=0; i<M; i++)
        {
            scanf("%lld", &m);

            if(jack[m] == 1)
                ++result;
        }

        printf("%lld\n", result);
    }

    return 0;
}
