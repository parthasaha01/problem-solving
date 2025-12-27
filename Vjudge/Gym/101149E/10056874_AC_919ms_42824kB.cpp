#include<bits/stdc++.h>
using namespace std;
#define mx 400005
struct dt
{
    int lb,ub;
}st[mx];
int tree[8*mx];

void update(int nd,int b,int e,int x,int y,int lz)
{
    if(lz!=0)tree[nd]+=lz;
    if(e<x||b>y)return;
    if(b>=x&&e<=y){
        tree[nd]+=1;
        return;
    }

    int lf = nd*2;
    int rg = lf+1;
    int md = (b+e)/2;

    update(lf,b,md,x,y,tree[nd]);
    update(rg,md+1,e,x,y,tree[nd]);
    tree[nd]=0;
}
int query(int nd,int b,int e,int x,int lz)
{
    if(b==x && e==x){
        return tree[nd]+lz;
    }

    int lf = nd*2;
    int rg = lf+1;
    int md = (b+e)/2;

    if(x<=md)return query(lf,b,md,x,tree[nd]+lz);
    else return query(rg,md+1,e,x,tree[nd]+lz);
}
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        set<int>ss;
        for(int i=1; i<=n; i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            st[i].lb = x;
            st[i].ub = y;
            ss.insert(x);
            ss.insert(y);
        }

        set<int>::iterator it;
        map<int,int>mp;
        int k=0;
        for(it=ss.begin(); it!=ss.end(); it++){
            mp[*it]=++k;
        }

        int sz = ss.size();
        memset(tree,0,sizeof(tree));

        int id = 0,mm=-1000000005;
        for(int i=1; i<=n; i++)
        {
            int x = mp[st[i].lb];
            int y = mp[st[i].ub];
            if(st[i].lb>mm){
                id = x;
                mm = st[i].lb;
            }
            update(1,1,sz,x,y,0);
        }
        int maxx = 0;
        for(int i=id; i<=sz; i++)
        {
            int res = query(1,1,sz,i,0);
            maxx=max(maxx,res);
        }

        printf("%d\n",maxx);
    }

    return 0;
}