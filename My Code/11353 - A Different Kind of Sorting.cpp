#include<bits/stdc++.h>
using namespace std;
int vis[2000005];
struct dt{
    int v,p;
}st[2000005];
bool cmp(dt a,dt b){
    if(a.p==b.p)return a.v<b.v;
    return a.p<b.p;
}
void sieve()
{
    for(int i=1; i<=2000000; i++)st[i].v=i,st[i].p=0;
    for(int i=2; i<=2000000; i++){
        if(vis[i]==0){
            for(int j=i; j<=2000000; j+=i){
                vis[j]=1;
                st[j].p++;
            }
        }
    }

    sort(st+1,st+2000001,cmp);
}
int main()
{
    sieve();
    int n,ks=0;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        printf("Case %d: %d\n",++ks,st[n].v);
    }
    return 0;
}
