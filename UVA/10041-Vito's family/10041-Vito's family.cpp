#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    long int Min, T, R, i, mid;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &R);

        long int ara[R];
        Min = 0;

        for(i=0; i<R; i++)
        {
            scanf("%ld", &ara[i]);
        }

        sort(ara, ara+R);

        mid = ara[R/2];

        for(i=0; i<R; i++)
        {
            Min += abs(mid-ara[i]);
        }

        printf("%ld\n", Min);
    }

    return 0;
}
