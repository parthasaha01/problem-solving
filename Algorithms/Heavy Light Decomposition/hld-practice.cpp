#include<bits/stdc++.h>
#define xx first
#define yy second

using namespace std;
#define root 1
#define MX 10002
#define inf 2000000000

int ts,kk=1;
int n,a[MX],sz[MX],level[MX],parent[MX],val[MX];
int nchain,child[MX],chainid[MX],chainpos[MX],head[MX];
vector<int> adj[MX],chain[MX];
pair<int,int> edge[MX];

void build(int chid,int idx,int st,int ed,int p,int v)
{
    if(st>ed) return;

    if(st==ed){
        chain[chid][idx]=v;
        return;
    }

    int lft=2*idx,rgt=lft+1,mid=(st+ed)/2;

    if(p<=mid) build(chid,lft,st,mid,p,v);
    else build(chid,rgt,mid+1,ed,p,v);

    chain[chid][idx]=max(chain[chid][lft],chain[chid][rgt]);

    return;
}

int query(int chid,int idx,int st,int ed,int s,int e)
{
    if(st>ed || s>e) return 0;

    if(st==s && ed==e) return chain[chid][idx];

    int lft=2*idx,rgt=lft+1,mid=(st+ed)/2;

    if(e<=mid) return query(chid,lft,st,mid,s,e);
    else if(s>mid) return query(chid,rgt,mid+1,ed,s,e);
    else return max(query(chid,lft,st,mid,s,mid),query(chid,rgt,mid+1,ed,mid+1,e));
}

void build_chain(int hd)
{
    vector<int>vv;

    for(int k=0,v=hd; v!=-1; k++,v=child[v]){
        vv.push_back(v);
        chainid[v]=nchain;
        chainpos[v]=k;
        head[v]=hd;
    }

    sz[nchain]=vv.size();

    chain[nchain].resize(4*sz[nchain],0);

    for(int i=0; i<(int)vv.size(); i++){
        build(nchain,root,0,sz[nchain]-1,chainpos[vv[i]],a[vv[i]]);
    }

//    printf("ChainNo - %d: ",nchain);
//    for(int i=0; i<vv.size(); i++){
//        printf("%d ",vv[i]);
//    }
//    printf("\n\n");

    nchain++;

    return;
}

int dfs(int u,int p,int d,int t)
{
    parent[u]=p;
    level[u]=d;
    child[u]=-1;
    int tmp,ret=1,mx=0;
    for(int i=0; i<(int)adj[u].size(); i++){
        int v=adj[u][i];
        if(v!=p){
            tmp=dfs(v,u,d+1,t);
            ret+=tmp;
            if(tmp>mx){
                mx=tmp;
                child[u]=v;
            }
        }
    }


    if(t){
        for(int i=0; i<(int)adj[u].size(); i++){
            if(adj[u][i]!=p && adj[u][i]!=child[u]) {
                build_chain(adj[u][i]);
            }
        }
    }

    return ret;
}

void HLD(int u)
{
    nchain=0;
    dfs(u,-1,0,1);
    build_chain(u);
    return;
}

int getLCA(int x,int y)
{
    while(chainid[x]!=chainid[y])
    {
        if(level[head[x]]>level[head[y]]) x=parent[head[x]];
        else y=parent[head[y]];
    }
    return (level[x]<level[y]?x:y);
}

int getQ(int x,int lca)
{
    if(x==lca) return -inf;

    int ret=-inf;
    while(level[x]>level[lca])
    {
        int l = (level[head[x]]>level[lca]) ? chainpos[head[x]] : chainpos[lca]+1;
        //int l = chainpos[head[x]];
        int r = chainpos[x];
        ret=max(ret,query(chainid[x],root,0,sz[chainid[x]]-1,l,r));
        x=parent[head[x]];
    }
    return ret;
}

int main()
{
    scanf("%d",&ts);
    while(ts--)
    {
        int q,t,x,y;
        scanf("%d",&n);

        for(int i=0; i<=n; i++){
            adj[i].clear(), a[i]=-inf;
        }

        for(int i=1; i<n; i++){
            scanf("%d%d%d",&edge[i].xx,&edge[i].yy,&val[i]);
            adj[edge[i].xx].push_back(edge[i].yy);
            adj[edge[i].yy].push_back(edge[i].xx);
        }

        dfs(1,-1,0,0);

        for(int i=1; i<n; i++){
            if(level[edge[i].xx]<level[edge[i].yy])
                swap(edge[i].xx,edge[i].yy);
            a[edge[i].xx]=val[i];
        }

        HLD(1);

        char c[10];

        while(scanf("%s",c) && c[0]!='D')
        {
            scanf("%d%d",&x,&y);

            if(c[0]=='C'){
                build(chainid[edge[x].xx],root,0,sz[chainid[edge[x].xx]]-1,chainpos[edge[x].xx],y);
            }
            else{
                int ans=-inf;

                if(x!=y){
                    int lca=getLCA(x,y);
                    ans=max(getQ(x,lca),getQ(y,lca));
                }

                if(ans==-inf) ans=0;

                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

/*
5
23
1 2 15
1 3 18
1 4 10
1 5 8
2 6 5
2 7 15
2 8 30
2 9 25
3 10 20
4 11 17
6 12 40
8 13 45
8 14 1
9 15 2
9 16 3
13 17 5
14 18 18
14 19 25
15 20 32
16 21 30
16 22 35
21 23 40


*/
