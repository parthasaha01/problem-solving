#include<iostream>
#include<cstdio>
using namespace std;
int gcd(long int a,long int b)
{
    if(b==0)
      return a;
    else
      return gcd(b,a%b);
}
int main()
{
    long int step,mode;
    int a;

    while(scanf("%ld%ld",&step,&mode)==2)
    {
            a=gcd(step,mode);

            if(a==1)
                printf("%10ld%10ld    Good Choice\n\n",step,mode);
            else
                printf("%10ld%10ld    Bad Choice\n\n",step,mode);
    }

    return 0;
}
