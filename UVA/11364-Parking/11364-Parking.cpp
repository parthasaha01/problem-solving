#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long int ara[20], T, n, diff, i;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &n);

        for(i=0; i<n; i++)
            scanf("%ld", &ara[i]);

        sort(ara, ara+n);

        diff = ara[n-1]-ara[0];

        printf("%ld\n", diff+diff);
    }

    return 0;
}
