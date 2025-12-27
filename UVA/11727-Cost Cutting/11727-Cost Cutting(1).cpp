#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long int T, a[3], i=0, j;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%ld %ld %ld", &a[0], &a[1], &a[2]);

        sort(a, a+3);

        printf("Case %ld: %ld\n", ++i, a[1]);

    }

    return 0;
}
