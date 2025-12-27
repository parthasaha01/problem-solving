#include<bits/stdc++.h>
using namespace std;
vector<int>ed[105];
int dp[105];
struct dd
{
    int t,p,s;
}st[105];
bool cmp(dd x, dd y)
{
    if(x.t==y.t){
        if(x.p==y.p){
            return x.s<y.s;
        }
        return x.p>y.p;
    }
    return x.t<y.t;
}
int fun(int u)
{
    if(ed[u].size()==0)return st[u].p;

    if(dp[u]!=-1)return dp[u];

    int ret = 0;
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        ret = max(ret,st[u].p+fun(v));
    }
    return dp[u] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k,t;
        scanf("%d%d%d",&n,&k,&t);

        for(int i=1; i<=n; i++){
            scanf("%d",&st[i].t);
        }
        for(int i=1; i<=n; i++){
            scanf("%d",&st[i].p);
        }
        for(int i=1; i<=n; i++){
            scanf("%d",&st[i].s);
        }

        sort(st+1,st+n+1,cmp);

        st[0].t=0; st[0].p=0; st[0].s=0;

        for(int i=0; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if((st[i].t==st[j].t) && (st[i].s!=st[j].s))continue;

                int dt = abs(st[i].t-st[j].t);
                int ds = abs(st[i].s-st[j].s);

                if(ds<=dt) ed[i].push_back(j);
            }
        }

        memset(dp,-1,sizeof(dp));
        int ans = fun(0);

        printf("%d\n",ans);
        if(ks<tt)printf("\n");

        for(int i=0; i<=n; i++)ed[i].clear();
    }
    return 0;
}
