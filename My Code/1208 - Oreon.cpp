#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int par[35];

struct edge{
    int u,v,w;
};
vector<edge>vv,pp;

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

int kruskal(int n)
{
    for(int i=1; i<=n; i++) par[i]=i;
    int sum=0,cnt=0; pp.clear();

    sort(vv.begin(),vv.end(),cmp);

    for(int i=0; i<vv.size(); i++)
    {
        edge top = vv[i];
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            pp.push_back(top);
            Unionparent(parU,parV);
            sum += top.w;
        }

    }

    vv.clear();

    return sum;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int w; char ch;
                scanf("%d%c",&w,&ch);
                if(i==j || w==0)continue;
                edge pp; pp.u=i, pp.v=j, pp.w=w;
                vv.push_back(pp);
            }
        }

        int mst = kruskal(n);

        printf("Case %d:\n",ks);
        for(int i=0; i<pp.size(); i++)
        {
            edge xx = pp[i];
            int u=xx.u, v=xx.v, w=xx.w;
            u--,v--;
            if(u>v)swap(u,v);
            printf("%c-%c %d\n",'A'+u,'A'+v,w);
        }

    }

    return 0;
}
