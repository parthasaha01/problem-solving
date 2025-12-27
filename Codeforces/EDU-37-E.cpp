#include<bits/stdc++.h>
//#include<tr1/unordered_map>
using namespace std;
//using namespace tr1;
pair<int,int>pi;
//unordered_map< pair<int,int>,int>mp;
map< pair<int,int>,int>mp;
#define mx 200005
int n,m,a[mx+5],vis[mx+5],pos,cnt;
int tree[mx*4];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[nd]=1;
        return;
    }
    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;
    init(lf,b,md);
    init(rg,md+1,e);
    tree[nd] = tree[lf]+tree[rg];
}
void update(int nd,int b,int e,int x)
{
    if(b==x&&e==x){
        tree[nd]=0;
        return;
    }
    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;
    if(x<=md)update(lf,b,md,x);
    else update(rg,md+1,e,x);
    tree[nd] = tree[lf]+tree[rg];
}
void query(int nd,int b,int e)
{
    if(b==e){
        if(vis[b]==0){
           pos = b;
           return;
        }
        else{
            pos = 0;
            return;
        }
    }

    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;

    if(tree[lf]>=1)query(lf,b,md);
    else query(rg,md+1,e);
}
void DFS(int u)
{
    vis[u] = 1;
    update(1,1,n,u);
    //printf("partha %d\n",u);
    cnt++;

    int bg=1;
    int ed=n;
    int ps=0;

    while(1)
    {
        if(bg>ed)break;
        query(1,bg,ed);
        if(pos==0)break;
        int ps=pos;

        if(vis[pos]==0)
        {
            int x = min(u,pos);
            int y = max(u,pos);
            pi = make_pair(x,y);
            if(mp.find(pi)==mp.end()){
                DFS(pos);
            }
        }
        bg = ps+1;
    }
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        pi = make_pair(u,v);
        mp[pi]=1;
    }

    init(1,1,n);

    //printf("partha1\n");

    int k=0;
    for(int i=1; i<=n; i++)
    {

        if(vis[i]==0)
        {
            cnt = 0;
            //printf("partha %d\n",i);
            DFS(i);
            a[++k] = cnt;
        }
    }

    sort(a+1,a+k+1);

    printf("%d\n",k);
    for(int i=1; i<=k; i++)
    {
        if(i==k)printf("%d\n",a[i]);
        else printf("%d ",a[i]);
    }

    return 0;
}
