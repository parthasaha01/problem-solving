#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long int n, i;

    while(scanf("%ld", &n) && n != 0)
    {
        long int ara[n];

        for(i=0; i<n; i++)
            scanf("%ld", &ara[i]);

        sort(ara, ara+n);

        for(i=0; i<n; i++)
        {
            printf("%ld", ara[i]);

            if(i < n-1)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
