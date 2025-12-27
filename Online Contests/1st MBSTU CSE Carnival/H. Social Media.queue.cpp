#include<bits/stdc++.h>
using namespace std;
#define mx 5005
map<int,int>mp;
vector<int>ed[mx+5];
int mf[mx+5];
bool vis[mx+5];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k; scanf("%d%d",&n,&k);

        mp.clear();
        for(int i=1; i<=n; i++)ed[i].clear();

        for(int i=1; i<=n; i++){
            int x; scanf("%d",&x);
            mp[x]=i;
        }

        for(int i=1; i<=n; i++){
            int ff; scanf("%d",&ff);
            int cnt=0;
            for(int j=1; j<=ff; j++){
                int x; scanf("%d",&x);
                if(mp[x]>=1 && mp[x]<=n){
                    ed[i].push_back(mp[x]);
                    cnt++;
                }
            }
            mf[i]=cnt;
        }

        queue<int>q;
        memset(vis,false,sizeof(vis));

        for(int i=1; i<=n; i++){
            if(mf[i]<k)q.push(i);
        }

        while(!q.empty())
        {
            int u = q.front();
            vis[u]=true;
            q.pop();


            for(int i=0; i<ed[u].size(); i++){
                int x = ed[u][i];
                if(vis[x])continue;
                mf[x]--;
                if(mf[x]<k)q.push(x);
            }
        }

        int cnt=0;
        for(int i=1; i<=n; i++){
            if(!vis[i])cnt++;
        }
        printf("Case %d: %d\n",ks,cnt);

    }
    return 0;
}
/*
2

5 5
1 2 3 4 5
1
2
2
2 3
2
2 4
3
3 5 10000
2
4 10000

5 1
1 2 3 4 5
1
2
2
1 3
2
2 4
2
3 10000
1
10000
*/
