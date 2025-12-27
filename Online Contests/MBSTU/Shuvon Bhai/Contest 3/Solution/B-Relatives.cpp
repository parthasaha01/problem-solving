#include <cstdio>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
long int phi(long int N)
{
    long int i,j,sq,cnt,flag,result;
    //cnt=0;
    result=N;
    //sq=sqrt((double)N);

    if((N&1)==0)    // N is even
    {
        while((N&1) == 0)
        {
           N=(N>>1);
           //cnt++;
        }

        result = (result>>1);   // result = (N/2)*(1)
    }
    for (i=3; i<=sqrt(N); i+=2)
    {
        //cnt=0;
        flag=0;
        while((N%i) == 0)
        {
           N=N/i;
           //cnt++;
           flag=1;
        }
        if(flag!=0)
            result = (result/i)*(i-1);

        if(N==1)
            break;
    }

    if(N>1)
    {
        result = (result/N)*(N-1);
    }

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
