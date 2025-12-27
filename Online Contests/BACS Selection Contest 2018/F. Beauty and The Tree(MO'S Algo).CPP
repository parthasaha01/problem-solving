#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int BLOCK = 320;
int dis[MAXN],fin[MAXN],nod[MAXN],lev[MAXN],wgt[MAXN];
int tree[4*MAXN],b[MAXN],ans[MAXN],tym,height;
vector<int>ed[MAXN];
struct dt{
    int l,r,i;
}qr[100005];
bool cmp(dt A, dt B){
  if (A.l / BLOCK != B.l / BLOCK) return A.l < B.l;
  return A.l / BLOCK % 2 ? A.r > B.r : A.r < B.r;
}

void dfs(int u,int p,int l)
{
    dis[u]   =  ++tym;
    nod[tym] =  u;
    lev[tym] =  l;
    wgt[tym] =  b[u];
    height = max(height,l);
    for(int i=0; i<ed[u].size(); i++){
        int v = ed[u][i];
        if(v==p)continue;
        dfs(v,u,l+1);
    }
    fin[u]=tym;
}
void update(int nd,int l,int r,int x,int v)
{
    if(l==r){
        tree[nd]+=v;
        return;
    }
    int m = (l+r)/2;
    if(x<=m)update(2*nd,l,m,x,v);
    else update(2*nd+1,m+1,r,x,v);
    tree[nd] = max(tree[2*nd],tree[2*nd+1]);
}
void Add(int x)
{
    update(1,1,height,lev[x],-wgt[x]);
    //printf("add x=%d lev=%d w=%d tree=%d\n",x,lev[x],-wgt[x],tree[1]);
}
void Remove(int x)
{
    update(1,1,height,lev[x],wgt[x]);
    //printf("remove x=%d lev=%d w=%d tree=%d\n",x,lev[x],wgt[x],tree[1]);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&b[i]);
        for(int i=2; i<=n; i++){
            int x; scanf("%d",&x);
            ed[x].push_back(i);
            ed[i].push_back(x);
        }

        tym = height = 0;
        dfs(1,0,1);
//        printf("height = %d\n\n",height);
//        for(int i=1; i<=n; i++){
//            printf("i=%d d=%d f=%d\n",i,dis[i],fin[i]);
//        }

        for(int i=1; i<=n; i++){
            qr[i].l = dis[i];
            qr[i].r = fin[i];
            qr[i].i = i;
        }

        sort(qr+1,qr+n+1,cmp);

//        for(int i=1; i<=n; i++){
//            printf("i=%d l=%d r=%d\n",qr[i].i,qr[i].l,qr[i].r);
//        }
//        printf("\n");

        int l=1,r=n;
        for(int i=1; i<=n; i++)
        {
            //printf("1 - l=%d r=%d\n",l,r);
            while(r<qr[i].r) Add(++r);
            //printf("2 - l=%d r=%d\n",l,r);
            while(r>qr[i].r) Remove(r--);
            //printf("3 - l=%d r=%d\n",l,r);
            while(l>qr[i].l) Add(--l);
            //printf("4 - l=%d r=%d\n",l,r);
            while(l<qr[i].l) Remove(l++);
            //printf("5 - l=%d r=%d\n",l,r);
            //printf("maxx=%d\n\n",tree[1]);
            ans[qr[i].i] = tree[1];
        }

        for(int i=2; i<=n; i++){
            printf("%d\n",ans[i]);
        }

        for(int i=1; i<=n; i++)ed[i].clear();
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
