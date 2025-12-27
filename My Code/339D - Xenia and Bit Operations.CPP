#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1<<17)+5;
int a[MAXN], tree[4*MAXN];
void update(int nd,int b,int e,int x,int v,int f)
{
    if(b==x&&e==x){ tree[nd]=v; return; }
    int md = (b+e)/2;
    if(x<=md)update(2*nd,b,md,x,v,1^f);
    else update(2*nd+1,md+1,e,x,v,1^f);
    if(f)tree[nd] = tree[2*nd] | tree[2*nd+1];
    else tree[nd] = tree[2*nd] ^ tree[2*nd+1];
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int m,q; cin>>m>>q;
    int n = (1<<m);

    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(1,1,n,i,a[i],m&1);
    }

    while(q--)
    {
        int x,v; cin>>x>>v;
        update(1,1,n,x,v,m&1);
        cout << tree[1] << endl;
    }
    return 0;
}
