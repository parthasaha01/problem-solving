#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
int a[mx+2],d[mx+2];
bool vis[mx+2];
int possible(int ed,int m)
{
    memset(vis,false,sizeof(vis));
    ll sum=0;
    for(int i=ed; i>=1; i--)
    {
        if(d[i]&&!vis[d[i]])
        {
            vis[d[i]]=true;
            if(i<=a[d[i]]){
                return 0;
            }
            sum-=a[d[i]];
        }
        else{
            sum++;
        }
    }

    if(sum<0) return 0;

    for(int i=1; i<=m; i++){
        if(!vis[i]) return 0;
    }
    return 1;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&d[i]);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
        }

        int lo=1,hi=n;
        int ans=-1;

        while(lo<=hi)
        {
            int md=(lo+hi)/2;
            if(possible(md,m)){
                hi=md-1;
                ans=md;
            }
            else{
                lo=md+1;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
