#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 150005
struct dt
{
   int x,y;
}pt[mx+5];
int qt[mx+5];
set<int>s;
map<int,int>mp;
int tree[8*mx];
void update(int nd,int b,int e,int x,int y)
{
    if(x>e||y<b) return;
    if(b>=x&&e<=y){
        tree[nd]+=1;
        return;
    }

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
}
int query(int nd,int b,int e,int x,int carry)
{
    if(x==b&&x==e) return carry+tree[nd];

    int lf=nd*2, rg=nd*2+1, md=(b+e)/2;

    if(x<=md)
        return query(lf,b,md,x,carry+tree[nd]);
    else
        return query(rg,md+1,e,x,carry+tree[nd]);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);

        int n,q;
        scanf("%d%d",&n,&q);
        s.clear();
        mp.clear();
        for(int i=1; i<=n; i++)
        {
            int ak,bk;
            scanf("%d%d",&ak,&bk);
            pt[i].x=ak;
            pt[i].y=bk;
            s.insert(ak);
            s.insert(bk);
        }

        for(int i=1; i<=q; i++)
        {
            int x;
            scanf("%d",&x);
            qt[i]=x;
            s.insert(x);

        }

        set<int>::iterator it;
        int k=1;
        for(it=s.begin(); it!=s.end(); it++)
        {
            mp[*it]=k;
            k++;
        }

        memset(tree,0,sizeof(tree));
        int sz=s.size();
        for(int i=1; i<=n; i++)
        {
            int x=mp[pt[i].x];
            int y=mp[pt[i].y];
            update(1,1,sz,x,y);
        }

        for(int i=1; i<=q; i++)
        {
            int x=mp[qt[i]];
            int ans=query(1,1,sz,x,0);
            printf("%d\n",ans);
        }
    }

    return 0;
}
