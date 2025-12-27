#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
#define sqmx 1000
bool prime[mx+2];
int dp[mx+2];
void seive()
{
    long i,j,di;
    for(i=3; i<=sqmx; i+=2)
    {
        if(prime[i]==false)//prime
        {
            di=i<<1;
            for(int j=i*i; j<=mx; j+=di)
            {
                prime[j]=true;
            }
        }
    }
}
bool digitSum(long a)
{
    int ret=0;

    while(a!=0)
    {
        ret += (a%10);
        a/=10;
    }

    if(ret==2)
        return true;
    else if(ret%2==0)
        return false;
    else
        return !prime[ret];
}
void digitPrime()
{
    int cnt=0;
    dp[2]=++cnt;

    for(int i=3; i<=mx; i+=2)
    {
        if(prime[i]==false && digitSum(i)==true)
        {
            dp[i]=++cnt;
        }
        else
        {
            dp[i]=cnt;
        }

        dp[i+1]=cnt;    // for even
    }
}
int main()
{
    seive();
    digitPrime();

    long N,t1,t2;
    scanf("%ld",&N);

    while(N--)
    {
        scanf("%ld %ld",&t1,&t2);
        printf("%d\n",dp[t2]-dp[t1-1]);
    }

    return 0;
}
