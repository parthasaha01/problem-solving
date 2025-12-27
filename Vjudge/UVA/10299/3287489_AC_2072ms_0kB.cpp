#include <cstdio>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
long int phi(long int N)
{
    long int i,j,sq,cnt,result;
    cnt=0;
    result=N;
    //printf("1.%ld ",result);
    sq=sqrt((double)N);
    if((N&1)==0)
    {
        while((N&1) == 0)
        {
           N=(N>>1);
           cnt++;
        }

        result = (result>>1);
        //printf("2.%ld ",result);
    }

    for (i=3; i<=sq; i+=2)
    {
        cnt=0;
        while((N%i) == 0)
        {
           N=N/i;
           cnt++;
        }
        if(cnt!=0)
            result = (result/i)*(i-1);
        //printf("3.%ld ",result);

        if(N==1)
            break;
    }

    if(N>1)
    {
        result = (result/N)*(N-1);
        //printf("4.%ld ",result);
    }

    //printf("5.%ld\n",result);

    return result;
}
int main()
{

    long int n;

    while(scanf("%ld",&n) && n)
    {
        if(n==1)
            printf("0\n");
        else
            printf("%ld\n",phi(n));

    }

    return 0;
}
