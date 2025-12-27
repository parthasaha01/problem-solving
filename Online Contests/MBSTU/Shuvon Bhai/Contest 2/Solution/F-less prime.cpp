#include<bits/stdc++.h>
using namespace std;
#define N 5250
#define sqN 72
int prime[700];
int num[5250];
int p;
void seive()
{
    int i,j;

    prime[p++]=2;

    for(i=3; i<=sqN; i+=2)
    {
        if(num[i]==0)
        {
            prime[p++]=i;

            for(j=i*i; j<=N; j+=(i+i))
            {
                num[j]=1;
            }
        }
    }
    for(i=sqN+1; i<=N; i+=2)
    {
        if(num[i]==0)
        {
            prime[p++]=i;
        }
    }
}
int main()
{
    seive();

    int T,n,i,result,m;

    scanf("%d",&T);
    //printf("p=%d\n",p);

    while(T--)
    {
        scanf("%d",&n);

        for(i=0;i<p;i++)
        {
            m=prime[i];
            if(m*2>n)
            {
                result = prime[i];
                break;
            }
        }

        printf("%d\n",result);
    }

    return 0;
}
