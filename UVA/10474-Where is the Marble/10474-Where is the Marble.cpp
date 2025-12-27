#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    long int N, Q, i, j=0, ans, x, y;

    while(scanf("%ld %ld", &N, &Q) ==2)
    {
        if(N == 0 && Q == 0)
            break;

        long int a[N], b[Q];

        for(i=0; i<N; i++)
            scanf("%ld", &a[i]);

        for(i=0; i<Q; i++)
            scanf("%ld", &b[i]);

        sort(a, a+N);

        printf("CASE# %ld:\n", ++j);

        for(y=0; y<Q; y++)
        {
            ans = 0;

            for(x=0; x<N; x++)
            {
                if(b[y] == a[x])
                {
                    ans=1;
                    break;
                }
            }

            if(ans == 1)
                printf("%ld found at %ld\n", b[y], x+1);

            else
                printf("%ld not found\n", b[y]);
        }
    }

    return 0;
}
