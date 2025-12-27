#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long int T,i,j,a[3];

    scanf("%ld",&T);
    for(i=1; i <= T; i++)
    {
        scanf("%ld %ld %ld", &a[0], &a[1], &a[2]);
        sort(a,a+3);

        if( (a[0]+a[1]) > a[2] )
        {
            printf("OK\n");
        }
        else
        {
            printf("Wrong!!\n");
        }
    }

    return 0;
}
