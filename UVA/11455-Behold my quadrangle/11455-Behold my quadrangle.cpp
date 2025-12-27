#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long int T,i,j,a[4];

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%ld",&a[j]);
        }
        sort(a,a+4);

        if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
        {
            printf("square\n");
        }
        else if(a[0]==a[1] && a[2]==a[3])
        {
            printf("rectangle\n");
        }
        else if( (a[0]+a[1]+a[2]) > a[3])
        {
            printf("quadrangle\n");
        }
        else
        {
            printf("banana\n");
        }
    }

    return 0;
}
