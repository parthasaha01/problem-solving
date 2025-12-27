#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int n,k,dp[205];
map< pair<int,int>, int>mp,mm;
vector<int>ed[205],cs[205];
struct dt
{
    int u,v,w;
}st[205];
int fun(int u)
{
    if(ed[u].size()==0)return 0;

    if(dp[u] != -1)return dp[u];

    int ret = 0;

    for(int i=0; i<ed[u].size(); i++)
    {
        int v = ed[u][i];
        int w = cs[u][i];
        ret = max(ret, w + fun(v));
    }

    return dp[u] = ret;
}
int main()
{
    int ks=0;
    while(scanf("%d",&n) && n)
    {
        mp.clear();
        mm.clear();

        k=0;

        for(int i=1; i<=n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);

            pii pp;

            pp = make_pair(u,v);
            if(mp[pp] ==0){
                ++k;
                st[k].u = u;
                st[k].v = v;
                st[k].w = w;
                mm[pp] = k;
                mp[pp] = w;
            }
            else{
                if(w>mp[pp]){
                    st[mm[pp]].w = w;
                    mp[pp] = w;
                }
            }

            pp = make_pair(v,u);
            if(mp[pp] ==0){
                ++k;
                st[k].u = v;
                st[k].v = u;
                st[k].w = w;
                mm[pp] = k;
                mp[pp] = w;
            }
            else{
                if(w>mp[pp]){
                    st[mm[pp]].w = w;
                    mp[pp] = w;
                }
            }

            pp = make_pair(u,w);
            if(mp[pp] ==0){
                ++k;
                st[k].u = u;
                st[k].v = w;
                st[k].w = v;
                mm[pp] = k;
                mp[pp] = v;
            }
            else{
                if(v>mp[pp]){
                    st[mm[pp]].w = v;
                    mp[pp] = v;
                }
            }

            pp = make_pair(w,u);
            if(mp[pp] ==0){
                ++k;
                st[k].u = w;
                st[k].v = u;
                st[k].w = v;
                mm[pp] = k;
                mp[pp] = v;
            }
            else{
                if(v>mp[pp]){
                    st[mm[pp]].w = v;
                    mp[pp] = v;
                }
            }

            pp = make_pair(v,w);
            if(mp[pp] ==0){
                ++k;
                st[k].u = v;
                st[k].v = w;
                st[k].w = u;
                mm[pp] = k;
                mp[pp] = u;
            }
            else{
                if(u>mp[pp]){
                    st[mm[pp]].w = u;
                    mp[pp] = u;
                }
            }

            pp = make_pair(w,v);
            if(mp[pp] ==0){
                ++k;
                st[k].u = w;
                st[k].v = v;
                st[k].w = u;
                mm[pp] = k;
                mp[pp] = u;
            }
            else{
                if(u>mp[pp]){
                    st[mm[pp]].w = u;
                    mp[pp] = u;
                }
            }
        }

        for(int i=1; i<=k; i++)
        {
            int u1,v1,w1;
            u1 = st[i].u;
            v1 = st[i].v;
            w1 = st[i].w;

            for(int j=1; j<=k; j++)
            {
                if(i==j)continue;

                int u2,v2,w2;
                u2 = st[j].u;
                v2 = st[j].v;
                w2 = st[j].w;

                if(u2<u1 && v2<v1){
                    ed[i].push_back(j);
                    cs[i].push_back(w2);
                }
            }
        }

        for(int j=1; j<=k; j++)
        {
            int w = st[j].w;
            ed[0].push_back(j);
            cs[0].push_back(w);
        }

        memset(dp,-1,sizeof(dp));

        int ans = fun(0);

        printf("Case %d: maximum height = %d\n",++ks,ans);

        for(int i=0; i<=k; i++)ed[i].clear();
        for(int i=0; i<=k; i++)cs[i].clear();
    }
    return 0;
}
