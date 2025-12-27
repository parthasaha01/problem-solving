#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[4*mx];
void update(int nd,int b,int e,int x,int y)
{
    if(e<x || b>y)return;

    if(b>=x&&e<=y){tree[nd]++; return;}

    int lf = 2*nd;
    int rg = lf+1;
    int md = (b+e)/2;

    update(lf,b,md,x,y);
    update(rg,md+1,e,x,y);
}
int query(int nd,int b,int e,int x,int pr)
{
    if(b==x&&e==x)return tree[nd]+pr;

    int lf = 2*nd;
    int rg = lf+1;
    int md = (b+e)/2;

    if(x<=md)return query(lf,b,md,x,tree[nd]+pr);
    else return query(rg,md+1,e,x,tree[nd]+pr);
}
int main()
{
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);

    memset(tree,0,sizeof(tree));

    for(int i=1; i<=m; i++)
    {
        int x,y; scanf("%d%d",&x,&y);

        if(x<=y){
            update(1,1,n,x,y);
        }
        else{
            update(1,1,n,x,n);
            update(1,1,n,1,y);
        }
    }

    int ans=0;

    for(int i=1; i<=n; i++){
        int cnt = query(1,1,n,i,0);
        if(cnt>1)ans++;
    }

    printf("%d\n",ans);

    return 0;
}
