#include<bits/stdc++.h>
using namespace std;
int par[10005],n,m,a,cnt;
struct edge{
    int u,v,w;
};
vector<edge>vv;
bool cmp(edge x, edge y)
{
    return x.w<y.w;
}
int findparent(int x)
{
    if(par[x]==x) return x;
    return par[x]=findparent(par[x]);
}
void Unionparent(int x,int y)
{
    par[findparent(y)] = findparent(x);
}

int kruskalMST()
{
    for(int i=1; i<=n; i++) par[i]=i;
    int sum=0;

    sort(vv.begin(),vv.end(),cmp);

    for(int i=0; i<vv.size(); i++)
    {
        edge top = vv[i];
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            Unionparent(parU,parV);
            sum += top.w;
        }
    }

    cnt=0;
    for(int i=1; i<=n; i++){
        if(par[i]==i)cnt++;
    }
    sum += (cnt*a);
    return sum;
}

int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&m,&a);
        vv.clear();

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);

            if(w>=a)continue;

            edge pp; pp.u=u, pp.v=v, pp.w=w;
            vv.push_back(pp);
        }

        int ans = kruskalMST();
        printf("Case #%d: %d %d\n",ks,ans,cnt);
    }

    return 0;
}

