#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>adj[mx];
int n,q,LOGN = 20, tym=0;
int depth[mx], parent[mx], startTime[mx], findNode[mx], pa[mx][20];
struct TreeData{
    int minn, maxx;
}tree[mx*4];

void Update(int node, int b, int e, int x, int v) {
    if(b==e && b==x) {
        tree[node].minn = v;
        tree[node].maxx = v;
        return;
    }

    int lson = 2*node, rson = 2*node+1, m = (b+e)/2;

    if(x<=m){
        Update(lson,b,m,x,v);
    }else{
        Update(rson,m+1,e,x,v);
    }

    tree[node].minn = min(tree[lson].minn,tree[rson].minn);
    tree[node].maxx = max(tree[lson].maxx,tree[rson].maxx);
}
void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].ver = b;
        tree[node].val = dis[b];
        tree_mn[node] = tree[node];
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    build(L,b,mid);
    build(R,mid+1,e);

    if(tree[L].val>tree[R].val)
    {
        tree[node] = tree[L];
    }
    else
    {
        tree[node] = tree[R];
    }

    if(tree_mn[L].val>tree_mn[R].val)
    {
        tree_mn[node] = tree_mn[R];
    }
    else
    {
        tree_mn[node] = tree_mn[L];
    }
}
TreeData Query(int node,int b,int e, int x, int y) {
    if((b>y || e<x) || (x>y)){
        TreeData temp;
        temp.minn = n+1;
        temp.maxx = 0;
        return temp;
    }

    if(b>=x && e<=y) return tree[node];

    int lson = 2*node, rson = 2*node+1, m = (b+e)/2;

    TreeData p1 = Query(lson, b, m, x, y);
    TreeData p2 = Query(rson, m+1, e, x, y);

    TreeData p;
    p.minn = min(p1.minn, p2.minn);
    p.maxx = max(p1.maxx, p2.maxx);
    return p;
}
int GetLca(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=LOGN-1; i>=0; i--){
        if(pa[u][i] != -1 && depth[u]-(1<<i) >= depth[v]){
            u = pa[u][i];
        }
    }
    if(u==v) return u;
    for(int i=LOGN-1; i>=0; i--){
        if(pa[u][i] != -1 && pa[u][i] != pa[v][i]){
            u = pa[u][i];
            v = pa[v][i];
        }
    }
    return parent[u];
}
void ProcessLca(){
    memset(pa,-1,sizeof(pa));
    for(int u=1; u<=n; u++){
        pa[u][0]=parent[u];
    }

    for(int i=1; i<LOGN; i++){
        for(int u=1; u<=n; u++){
            if(pa[u][i-1]!=-1){
                pa[u][i] = pa[pa[u][i-1]][i-1];
            }
        }
    }
}
void DFS(int u,int prev,int _depth=0){
    depth[u] = _depth;
    parent[u] = prev;
    startTime[u] = ++tym;
    findNode[tym] = u;
    for(int i=0; i<adj[u].size(); i++)    {
        int v = adj[u][i];
        if(v!=prev){
            DFS(v,u,_depth+1);
        }
    }
}
void preprocess(){
    tym = 0;
    DFS(1,0);

//    for(int i=1; i<=n; i++){
//        cout<<i<<" "<<startTime[i]<<endl;
//    }

    ProcessLca();

    for(int i=1; i<=n; i++) {
        Update(1,1,n,i,startTime[i]);
    }
}

int solve(int u, int l, int r){
    int x1 = l, y1 = u-1;
    int x2 = u+1, y2 = r;

    int minn = 1000000, maxx = -1000000;

    if(x1<=y1){
        TreeData ret = Query(1,1,n,x1,y1);
        maxx = max(maxx, ret.maxx);
        minn = min(minn, ret.minn);
        //printf("rminn1=%d rmaxx1=%d\n",ret.minn,ret.maxx);
    }



    if(x2<=y2){
        TreeData ret = Query(1,1,n,x2,y2);
        maxx = max(maxx, ret.maxx);
        minn = min(minn, ret.minn);
        //printf("rminn2=%d rmaxx2=%d\n",ret.minn,ret.maxx);
    }



    int lca = GetLca(findNode[minn],findNode[maxx]);

    //printf("minn=%d maxx=%d u=% v=%d lca=%d depth=%d\n",minn,maxx,findNode[minn],findNode[maxx],lca,depth[lca]);

    return depth[lca];
}
int main(){
    scanf("%d%d",&n,&q);
    for(int u=2; u<=n; u++){
        int p; scanf("%d",&p);
        adj[p].push_back(u);
        adj[u].push_back(p);
    }

    preprocess();

    for(int i=1; i<=q; i++) {
        int l,r; scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);

        TreeData ret = Query(1,1,n,l,r);

        int u = findNode[ret.minn];
        int v = findNode[ret.maxx];

        //printf("minn=%d maxx=%d u=%d v=%d\n",ret.minn,ret.maxx,u,v);

        int resu = solve(u,l,r);
        int resv = solve(v,l,r);

        if(resu>=resv) {
            printf("%d %d\n",u,resu);
        }else{
            printf("%d %d\n",v,resv);
        }
    }

    return 0;
}

