#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int rgt[mx],lft[mx],a[mx],c[mx];
int tree[4*mx];
map<int,int>mp;
void update(int nd,int b,int e,int x,int v)
{
    if(b==x&&e==x){
        tree[nd] = max(tree[nd],v);
        return;
    }

    int lf=2*nd, rg = 2*nd+1, md=(b+e)/2;

    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    tree[nd] = max(tree[lf],tree[rg]);
}
int query(int nd,int b,int e,int x,int y)
{
    if(x>y)return 0;
    if(b>y||e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];

    int lf=2*nd, rg = 2*nd+1, md=(b+e)/2;

    int p1 = query(lf,b,md,x,y);
    int p2 = query(rg,md+1,e,x,y);
    return max(p1,p2);
}
int main()
{
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            c[i] = a[i];
        }

        sort(c+1,c+n+1);

        mp.clear();
        int k = 0;
        for(int i=1; i<=n; i++){
            if(mp.find(c[i])==mp.end())mp[c[i]] = ++k;
        }

        for(int i=1; i<=n; i++){
            a[i] = mp[a[i]];
        }

        lft[1] = 1;
        for(int i=2; i<=n; i++){
            if(a[i]>a[i-1]){
                lft[i] = lft[i-1]+1;
            }
            else{
                lft[i] = 1;
            }
        }

        rgt[n] = 1;
        for(int i=n-1; i>=1; i--){
            if(a[i]<a[i+1]){
                rgt[i] = rgt[i+1]+1;
            }
            else{
                rgt[i] = 1;
            }
        }

        memset(tree,0,sizeof(tree));
        int ans = 0;

        for(int i=1; i<=n; i++)
        {
            int cnt = 0;
            cnt += rgt[i];
            cnt += query(1,1,k,1,a[i]-1);

            ans = max(ans,cnt);
            update(1,1,k,a[i],lft[i]);
        }

        printf("%d\n",ans);
    }
    return 0;
}
