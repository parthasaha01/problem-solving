#include<bits/stdc++.h>
using namespace std;
int prime[30];
int fac[105][30];
int ans[105][30];
bool vis[105];
void sieve()
{
    int k=0;
    prime[k++]=2;
    for(int i=3;i<101;i+=2){
        if(!vis[i]){
            prime[k++]=i;
            for(int j=i*i;j<101;j+=i+i){
                vis[j]=true;
            }
        }
    }
}
void factorization()
{
    for(int i=2; i<=100; i++)
    {
        int n=i;
        for(int j=0;j<25;j++)
        {
            int cnt=0;
            while(n%prime[j]==0)
            {
                ++cnt;
                n/=prime[j];
            }
            fac[i][j]=cnt;
        }
    }

    for(int i=2; i<=100; i++)
    {
        for(int j=0; j<25; j++){
            ans[i][j]=ans[i-1][j]+fac[i][j];
        }
    }
}
int main()
{
    sieve();
    factorization();
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d =",ks,n);
        bool flag=true;
        for(int i=0; i<25; i++)
        {
            if(ans[n][i]!=0){
                if(flag){
                    printf(" %d (%d)",prime[i],ans[n][i]);
                    flag=false;
                }
                else{
                    printf(" * %d (%d)",prime[i],ans[n][i]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
