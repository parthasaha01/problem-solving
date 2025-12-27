#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define mx 5005
map<int,int>mp;
vector<int>ed[mx+5];
int mf[mx+5],tree[4*mx];
bool vis[mx+5];
void init(int nd,int b,int e)
{
    if(b==e){tree[nd]=b; return;};
    int lf=2*nd,rg=2*nd+1,md=(b+e)/2;

    init(lf,b,md);
    init(rg,md+1,e);

    if(mf[tree[lf]]<=mf[tree[rg]]) tree[nd]=tree[lf];
    else tree[nd]=tree[rg];
}
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        mf[x]+=v;
        return;
    }
    int lf=2*nd,rg=2*nd+1,md=(b+e)/2;
    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    if(mf[tree[lf]]<=mf[tree[rg]]) tree[nd]=tree[lf];
    else tree[nd]=tree[rg];
}
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

        init(1,1,n);
        memset(vis,false,sizeof(vis));

        while(mf[tree[1]]<k)
        {
            int u = tree[1];
            update(1,1,n,u,inf);

            vis[u]=true;

            for(int i=0; i<ed[u].size(); i++){
                int x = ed[u][i];
                if(vis[x])continue;
                update(1,1,n,x,-1);
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
