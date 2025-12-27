#include<bits/stdc++.h>'
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
}tree[4*1000005];

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
info ddd(info x, info y)
{
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
info query(int n,int b,int e,int x,int y)
{
    if(b>y || e<x){
        info xx;
        xx.l=xx.r=0;
        return xx;
    }
    if(b>=x && e<=y){
        return tree[n];
    }
    info p1 = query(lft,b,mid,x,y);
    info p2 = query(ryt,mid+1,e,x,y);
    return ddd(p1,p2);
}
int main()
{
    int n,cs=1;
    while(cin>>s)
    {
        int n = s.size();
        s = "0" + s;

        for(int i=1; i<=n; i++){
            if(s[i]=='O')s[i]='(';
            else s[i]=')';
        }
        Build(1,1,n);
        int q; scanf("%d",&q);
        while(q--)
        {
            getchar();
            char ch; scanf("%c",&ch);
            if(ch=='R'){
                int x; scanf("%d",&x);
                s[x] = (s[x]=='(') ? ')' : '(';
                Update(1,1,n,x);
            }
            else{
                int x,y; scanf("%d%d",&x,&y);
                info ans = query(1,1,n,x,y);
                int  res = ans.l+ans.r;
                res = (y-x+1)-res;
                printf("%d\n",res);
            }
        }
    }
	return 0;
}

