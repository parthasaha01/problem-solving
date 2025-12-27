#include<bits/stdc++.h>
using namespace std;
int par[105],nn;
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

int kruskalMST(int node)
{
    for(int i=1; i<=node; i++) par[i]=i;
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
            if(cnt==node-1)break;
        }

    }

    vv.clear();

    if(cnt<node-1)return -1;
    return sum;
}

int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
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

        int ans = kruskalMST(k);

        if(ans==-1)printf("Case %d: Impossible\n",ks);
        else printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}


