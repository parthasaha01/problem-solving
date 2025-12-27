#include<bits/stdc++.h>
using namespace std;
#define mx 105
struct dt{int id,cc;};
dt dp[mx];
vector<int>ed[mx];
dt fun(int u)
{
    if(ed[u].size()==0){
        dp[u].cc = 0;
        dp[u].id = u;
        return dp[u];
    }

    if(dp[u].cc!=-1)return dp[u];

    dt ret;
    ret.cc = 0;
    ret.id = 105;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];

        dt cnt = fun(v);
        cnt.cc ++;

        if(cnt.cc>=ret.cc)
        {
            if(cnt.cc == ret.cc){
                if(cnt.id<ret.id){
                    ret.id = cnt.id;
                }
            }
            else{
                ret.cc = cnt.cc;
                ret.id = cnt.id;
            }
        }
    }

    return dp[u] = ret;
}
int main()
{
    int ks=0;
    int n;
    while(scanf("%d",&n) && n)
    {
        int s; scanf("%d",&s);

        int u,v;
        while(scanf("%d%d",&u,&v))
        {
            if(u==0&&v==0)break;
            ed[u].push_back(v);
        }

        for(int i=0; i<=n; i++){
                dp[i].cc=-1;
                dp[i].id=i;
        }

        dt ans = fun(s);

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++ks,s,ans.cc,ans.id);

        for(int i=0; i<=n; i++)ed[i].clear();
    }
    return 0;
}
