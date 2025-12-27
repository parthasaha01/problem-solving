#include<bits/stdc++.h>
using namespace std;
int par[205],n,m,a,cnt;
struct edge{
    int u,v,w;
};
vector<edge>vv,uu;
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
    int sum=0,cnt=0;

    sort(vv.begin(),vv.end(),cmp);
    uu.clear();

    for(int i=0; i<vv.size(); i++)
    {
        edge top = vv[i];
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            Unionparent(parU,parV);
            sum += top.w;
            cnt++;
            edge pp; pp.u=top.u, pp.v=top.v, pp.w=top.w;
            uu.push_back(pp);
        }
    }

    vv.clear();
    vv = uu;

    if(cnt==n-1)return sum;
    return -1;
}

int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);
        scanf("%d%d",&n,&m);
        vv.clear();

        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge pp; pp.u=u, pp.v=v, pp.w=w;
            vv.push_back(pp);

            int ans = kruskalMST();
            printf("%d\n",ans);
        }
    }

    return 0;
}

