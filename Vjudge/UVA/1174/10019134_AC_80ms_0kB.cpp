#include<bits/stdc++.h>
using namespace std;
int par[2005],nn;
map<string,int>mp;
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

int kruskalMST(int n)
{
    for(int i=1; i<=n; i++) par[i]=i;
    int sum=0,cnt=0;

    sort(vv.begin(),vv.end(),cmp);

    for(int i=0; i<vv.size(); i++)
    {
        edge top = vv[i];
        int parU = findparent(top.u);
        int parV = findparent(top.v);

        if(parU!=parV){
            Unionparent(parU,parV);
            sum += top.w;
            cnt++;
            if(cnt==n-1)break;
        }

    }

    vv.clear();

    return sum;
}

int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=0; ks<tt; ks++)
    {
        if(ks)printf("\n");

        int n; scanf("%d",&n);
        int m; scanf("%d",&m);

        int k=0;
        mp.clear();

        for(int i=1; i<=m; i++)
        {
            string s1,s2; int u,v,w;
            cin >> s1 >> s2 >> w;

            if(mp[s1]==0)mp[s1]=++k;
            if(mp[s2]==0)mp[s2]=++k;

            u = mp[s1], v = mp[s2];
            edge pp; pp.u=u, pp.v=v, pp.w=w;
            vv.push_back(pp);
        }

        int ans = kruskalMST(n);

        printf("%d\n",ans);
    }

    return 0;
}
