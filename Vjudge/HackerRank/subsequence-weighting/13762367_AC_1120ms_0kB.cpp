#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 150005
map<int,int>mp;

int a[mx],n,b[mx];
ll w[mx],vv[mx],tree[4*mx];
void update(int nd,int b,int e,int x,ll v)
{
    if(b==x&&e==x){
        tree[nd] = v;
        return ;
    }

    int lf = 2*nd; int rg = 2*nd+1; int md = (b+e)/2;

    if(x<=md)update(lf,b,md,x,v);
    else update(rg,md+1,e,x,v);

    tree[nd] =max(tree[lf],tree[rg]);

}
ll query(int nd,int b,int e,int x,int y)
{
    if(x>y)return 0LL;
    if(b==x &&e==y){
        return tree[nd];
    }

    int lf = 2*nd; int rg = 2*nd+1; int md = (b+e)/2;

    if(y<=md){
        return query(lf,b,md,x,y);
    }
    else if(x>md){
        return query(rg,md+1,e,x,y);
    }
    else{
        ll p1 = query(lf,b,md,x,md);
        ll p2 = query(rg,md+1,e,md+1,y);
        return max(p1,p2);
    }
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            b[i] = a[i];
        }

        sort(b+1,b+n+1);

        mp.clear();
        int k = 0;
        for(int i=1; i<=n; i++){
            if(mp.find(b[i])==mp.end())mp[b[i]]=++k;
        }

        int N = k;

        for(int i=1; i<=n; i++){
            scanf("%lld",&w[i]);
        }

        memset(tree,0,sizeof(tree));
        memset(vv,0,sizeof(vv));

        for(int i=n; i>=1; i--)
        {
            //printf("partha\n");
            int id = mp[a[i]];
            ll val = query(1,1,N,id+1,N);
            ll sum = val+w[i];

            //printf("i=%d id=%d sum=%lld val=%lld\n",i,id,sum,val);
            if(sum>vv[id]){
                update(1,1,N,id,sum);
                vv[id] = sum;
            }
        }

        ll ans = 0;
        for(int i=1; i<=N; i++){
            ans = max(vv[i],ans);
        }

        printf("%lld\n",ans);

    }
    return 0;
}


