#include<bits/stdc++.h>
using namespace std;
bool isprime[105],vis[2005];
int cost[2005];
vector<int>prime;
vector<int>factor[1005];
void sieve()
{
    memset(isprime,true,sizeof(isprime));

    for(int i=4; i<=102; i+=2){
        isprime[i]=false;
    }
    prime.push_back(2);
    for(int i=3;i<=102; i+=2){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=i*i; j<=102; j+=2*i){
                isprime[j]=false;
            }
        }
    }
}
void factorization(int num)
{
    int n=num;
    factor[num].clear();

    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            factor[num].push_back(prime[i]);

            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
        }
    }

    if(n>1&&n!=num){
        factor[num].push_back(n);
    }

}
int bfs(int s,int d)
{
    memset(vis,false,sizeof(vis));

    cost[s]=0;
    vis[s]=true;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<factor[u].size(); i++)
        {
            int v=u+factor[u][i];
            //printf("u=%d prime=%d v=%d\n",u,prime[i],v);

            if(v<=d&&!vis[v])
            {
                cost[v]=cost[u]+1;
                vis[v]=true;
                if(v==d){
                    return cost[v];
                }
                q.push(v);
            }
        }
    }

    return -1;
}
int main()
{
    sieve();
    for(int i=2; i<1003; i++){
        factorization(i);
    }

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int s,d;
        scanf("%d%d",&s,&d);

        int ans=0;
        if(s==d){
            ans=0;
        }
        else if(isprime[s]){
            ans=-1;
        }
        else{
            ans=bfs(s,d);
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
