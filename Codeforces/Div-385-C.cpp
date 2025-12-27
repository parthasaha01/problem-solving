#include<bits/stdc++.h>
using namespace std;
#define mx 100005
bool sp[1005];
int vcl[1005];
vector<int>ed[1005];
int ka[1005];
int cl[1005];
int n,m,k,sum,cnt;
int dfscl(int u,int p)
{
    vcl[u] = p;
    cnt++;
    sum += ed[u].size();
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(vcl[v]==0){
            dfscl(v,p);
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        memset(sp,false,sizeof(sp));
        for(int i=0; i<=n; i++){
            ed[i].clear();
        }

        for(int i=1; i<=k; i++){
            scanf("%d",&ka[i]);
            sp[ka[i]] = true;
        }

        for(int i=1; i<=m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].push_back(v);
            ed[v].push_back(u);
        }

        memset(vcl,0,sizeof(vcl));
        int ans = 0;
        int maxx = 0;
        for(int i=1; i<=k; i++)
        {
            int p = ka[i];
            sum = 0;
            cnt = 0;
            dfscl(p,p);
            maxx = max(cnt,maxx);

            ans += ((cnt*(cnt-1))/2) - (sum/2);
        }

        for(int i=1; i<=n; i++)
        {
            int u = i;

            if(vcl[u]==0)
            {
                sum = 0;
                cnt = 0;
                dfscl(u,u);
                ans += ((cnt*(cnt-1))/2) - (sum/2);
                ans += cnt*maxx;
                maxx += cnt;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
