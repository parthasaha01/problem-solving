#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[8*mx];
bool flag[mx];
struct dt{
    int xx,yy;
}st[mx];
void update(int nd,int b,int e,int x,int y,int v)
{
    if(b>y || e<x)return;

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;
    if(tree[nd]!=0&&b!=e){
        tree[lf] = tree[nd];
        tree[rg] = tree[nd];
        tree[nd] = 0;
    }

    if(b>=x&&e<=y){
        tree[nd] = v;
        return;
    }

    update(lf,b,md,x,y,v);
    update(rg,md+1,e,x,y,v);
}
int query(int nd,int b,int e,int x,int pr)
{
    if(b==x&&e==x){
        if(pr==0)return tree[nd];
        return pr;
    }

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;

    if(pr==0)pr = tree[nd];

    if(x<=md) return query(lf,b,md,x,pr);
    else return query(rg,md+1,e,x,pr);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int q; scanf("%d",&q);

        set<int>ss;
        for(int i=1; i<=q; i++){
            int xx,yy;
            scanf("%d %d",&xx,&yy);
            st[i].xx = xx;
            st[i].yy = yy;
            ss.insert(xx);
            ss.insert(yy);
        }

        map<int,int>mp;
        set<int> :: iterator it;
        int n = 0;
        for(it=ss.begin(); it!=ss.end(); it++){
            mp[*it] = ++n;
        }

        n = ss.size();

        memset(tree,0,sizeof(tree));

        for(int i=1; i<=q; i++){
            int xx = st[i].xx;
            int yy = st[i].yy;
            xx = mp[xx];
            yy = mp[yy];
            update(1,1,n,xx,yy,i);
        }

        memset(flag,false,sizeof(flag));
        for(it=ss.begin(); it!=ss.end(); it++){
            int p = *it;
            p = mp[p];
            int cl = query(1,1,n,p,0);
            flag[cl] = true;
        }

        int ans = 0;
        for(int i=1; i<=q; i++)if(flag[i])ans++;
        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
