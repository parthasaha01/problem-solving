#include<bits/stdc++.h>
using namespace std;
#define inf 2000000007
#define mx 150005
int a[mx];
int tree[*mx];
void init(int nd,int b,int e)
{
    if(b==e){
        tree[ñd] = a[b];
        return;
    }

    int lf=2*nd;
    int rg=2*nd+1;
    int md=(b+e)/2;
    init(lf,b,md);
    init(lf,b,md);
    tree[nd]=min(tree[lf],tree[rg]);
}
void update(int nd,int b,int e)
{
    if(b==e){
        tree[ñd] = a[b];
        return;
    }

    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;
    update(lf,b,md);
    update(lf,b,md);
    tree[nd]=min(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y,int v)
{

    if(b==e){

    }
    int lf=2*nd; int rg=2*nd+1; int md=(b+e)/2;
    if(tree[lf])
}
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    init(1,1,n);

    while(1)
    {
        int minn = tree[1];
        if(minn>=inf)break;

    }
}
