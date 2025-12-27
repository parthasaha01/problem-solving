#include<bits/stdc++.h>
using namespace std;
#define MX 300005
struct DT{ int l,r,x; };
DT qr[MX];
int n,m,ans[MX],tree[4*MX];
void update(int nd,int b,int e,int l,int r,int v)
{
    if(r<l||l<1||r>n)return;
    if(b>r||e<l)return;
    if(tree[nd]!=0 && b!=e){
        tree[2*nd] = tree[nd];
        tree[2*nd+1] = tree[nd];
        tree[nd]=0;
    }
    if(b>=l&&e<=r){ tree[nd] = v; return; }
    int md = (b+e)/2;
    update(2*nd,b,md,l,r,v);
    update(2*nd+1,md+1,e,l,r,v);
}
int query(int nd,int b,int e,int x,int v)
{
    if(b==e){
        if(v==0)return tree[nd];
        else return v;
    }
    int md = (b+e)/2;
    if(v==0)v=tree[nd];
    if(x<=md)return query(2*nd,b,md,x,v);
    else return query(2*nd+1,md+1,e,x,v);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        cin>>qr[i].l>>qr[i].r>>qr[i].x;
    }

    for(int i=m; i>=1; i--)
    {
        int l,r,x;
        l=qr[i].l; r=qr[i].r; x=qr[i].x;
        if(x>=l&&x<=r){
            update(1,1,n,l,x-1,x);
            update(1,1,n,x+1,r,x);
        }
        else{
            update(1,1,n,l,r,x);
        }
    }

    for(int i=1; i<=n; i++){
        ans[i] = query(1,1,n,i,0);
    }

    for(int i=1; i<=n; i++){
        if(i<n)cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }

    return 0;
}
