#include<bits/stdc++.h>
using namespace std;
#define mx 100005
map<int,int>mp;
map<int,int>sp;
int a[mx],tree[4*mx];
struct dt{
    int t,v;
}qr[mx];
void update(int nd,int b,int e,int x)
{
    if(b==e){
        if(a[x]>0)tree[nd] = sp[x];
        else tree[nd] = 0;
        return;
    }

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;

    if(x<=md)update(lf,b,md,x);
    else update(rg,md+1,e,x);

    tree[nd] = __gcd(tree[lf],tree[rg]);
}
int main()
{
    int q; scanf("%d",&q);
    int k = 0;
    for(int i=1; i<=q; i++){
        getchar();
        char ch; int v;
        scanf("%c %d",&ch,&v);
        if(ch=='+'){
            if(mp.find(v)==mp.end()){
                mp[v] = ++k;
                sp[k] = v;
            }
            qr[i].t = 1;
            qr[i].v = mp[v];

        }
        else{
            qr[i].t = 2;
            qr[i].v = mp[v];
        }
    }

    int n = k;

    for(int i=1; i<=q; i++)
    {
        int t = qr[i].t;
        int v = qr[i].v;

        if(t==1){
            a[v]++;
            if(a[v]==1)update(1,1,n,v);
            printf("%d\n",max(1,tree[1]));
        }
        else{
            a[v]--;
            if(a[v]==0)update(1,1,n,v);
            printf("%d\n",max(1,tree[1]));
        }
    }

    return 0;
}
