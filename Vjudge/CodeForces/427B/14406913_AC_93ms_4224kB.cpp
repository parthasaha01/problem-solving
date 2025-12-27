#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int n,t,c,a[mx],tree[4*mx];
void build(int nd,int b,int e)
{
    if(b==e){ tree[nd] = a[b]; return; }
    int md = (b+e)/2;
    build(2*nd,b,md);
    build(2*nd+1,md+1,e);
    tree[nd] = max(tree[2*nd],tree[2*nd+1]);
}
int query(int nd,int b,int e,int l,int r)
{
    if(b>r||e<l)return 0;
    if(b>=l&&e<=r)return tree[nd];
    int md = (b+e)/2;
    int p1 = query(2*nd,b,md,l,r);
    int p2 = query(2*nd+1,md+1,e,l,r);
    return max(p1,p2);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin>>n>>t>>c;
    for(int i=1; i<=n; i++)cin>>a[i];

    build(1,1,n);

    int ans = 0;
    for(int i=1; i+c-1<=n; i++)
    {
        int maxx = query(1,1,n,i,i+c-1);
        if(maxx<=t)ans++;
    }

    cout << ans << endl;

    return 0;
}
