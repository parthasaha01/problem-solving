#include<bits/stdc++.h>
using namespace std;
#define lft n<<1
#define ryt (n<<1)+1
#define mid (int)((b+e)>>1)
#define L tree[lft]
#define R tree[ryt]
#define N tree[n]
string s;
struct info{
int l,r;
}tree[4*30004];

void setN(int n, int x){
    N.l = N.r = 0;
    if(s[x]=='(') N.l=1;
    else N.r=1;
}
info add(info x, info y){
    int clr = min(x.l,y.r);
    x.l = x.l - clr; y.r = y.r - clr;
    info z;
    z.l = x.l + y.l; z.r = x.r + y.r;
    return z;
}
void Build(int n, int b, int e){
    if(b==e){ setN(n,b); return; }
    Build(lft,b,mid);
    Build(ryt,mid+1,e);
    N = add(L,R);
}
void Update(int n, int b, int e, int x){
    if(b>x || e<x) return;
    if(b==e && b==x){ setN(n,b); return; }
    Update(lft,b,mid,x);
    Update(ryt,mid+1,e,x);
    N = add(L,R);
}
int main()
{
    int n,cs=1;
    while(scanf("%d",&n)==1)
    {
        printf("Test %d:\n",cs++);
        cin>>s; s = "0" + s;
        Build(1,1,n);
        int q; scanf("%d",&q);
        while(q--)
        {
            int x; scanf("%d",&x);
            if(x){
                s[x] = (s[x]=='(') ? ')' : '(';
                Update(1,1,n,x);
            }
            else{
                if(!tree[1].l&&!tree[1].r) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
	return 0;
}

