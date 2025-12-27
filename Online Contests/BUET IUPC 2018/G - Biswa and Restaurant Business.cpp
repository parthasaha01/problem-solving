#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
#define MOD 1000000007LL
ll a[mx],b[mx],lft[mx],rgt[mx],st[mx][20];
void sparsetable(ll m)
{
    for(int i=1; i<=m; i++)st[i][0] = i;
    for(int j=1; (1<<j)<=m; j++){
        for(int i=1; (i+(1<<j)-1)<=m; i++){
            int x = st[i][j-1];
            int y = st[i+(1<<(j-1))][j-1];
            if(b[x]>=b[y])st[i][j] = x;
            else st[i][j] = y;
        }
    }
}
ll query(int l,int r)
{
    if(l>r)swap(l,r);
    int p = (int)log2(r-l+1);
    if(b[st[l][p]] >= b[st[r-(1<<p)+1][p]])
    return st[l][p];
    return st[r-(1<<p)+1][p];
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n,k; scanf("%lld%lld",&n,&k);

        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }
        a[0] = 0;
        lft[0] = 0;
        for(int i=1; i<=n; i++){
            if(a[i]>a[i-1]){
                lft[i] = min(k,lft[i-1]+1);
            }
            else{
                lft[i] = 1;
            }
        }

        a[n+1] = 100000005;
        rgt[n+1] = 0;
        for(int i=n; i>=1; i--){
            if(a[i]<a[i+1]){
                rgt[i] = min(k,rgt[i+1]+1);
            }
            else{
                rgt[i] = 1;
            }
        }

//        for(int i=1; i<=n; i++){
//            printf("%d ",lft[i]);
//        }
//        printf("\n");
//
//        for(int i=1; i<=n; i++){
//            printf("%d ",rgt[i]);
//        }
//        printf("\n");

        ll sum = 0;
        for(int i=1; i<=k; i++){
            sum += lft[i];
        }
        b[1] = sum;

        for(int i=k+1; i<=n; i++){
            sum -= rgt[i-k];
            sum += lft[i];
            b[i-k+1] = sum;
        }

        ll m = n-k+1;

//        for(int i=1; i<=m; i++){
//            printf("%d ",b[i]);
//        }
//        printf("\n");

        sparsetable(m);

        ll ans = 0;
        ll tot = 0;
        for(int i=1; i<=m; i++)
        {
            int lo = i, hi = m;
            int id = i;
            while(lo<=hi)
            {
                int md = (lo+hi)/2;
                int x = query(lo,md);
                if(b[x]<=b[i]){
                    id = md;
                    lo = md+1;
                }
                else{
                    hi = md-1;
                }
            }
            ll p = id-i+1;
//            tot += p;
//            ans += (b[i]*p);
//            ans %= MOD;

            //if(i==1)continue;

            lo = 1, hi = i-1;
            id = i;
            while(lo<=hi)
            {
                int md = (lo+hi)/2;
                int x = query(md,hi);
                //printf("id = %d lo=%d hi=%d md=%d x=%d b[x]=%lld b[i]=%lld\n",id,lo,hi,md,x,b[x],b[i]);
                if(b[x]<b[i]){
                    id = md;
                    hi = md-1;
                }
                else{
                    lo = md+1;
                }
            }

            ll q = max(1,i-id+1);
            ll pq = (p*q)%MOD;

            //printf("i=%d b[i]=%lld p=%lld q=%lld pq=%lld\n\n",i,b[i],p,q,pq);

            ans += (b[i]*pq);
            ans %= MOD;
            //ans -= b[i];
            //if(ans<0)ans = (ans+MOD)%MOD;
        }

        //printf("tot=%lld\n",tot);

//        ll res = 0;
//
//        for(int i=1; i<=m; i++){
//            ll maxx = 0;
//            for(int j=i; j<=m; j++){
//                maxx = max(maxx,b[j]);
//                res += maxx;
//                res %= MOD;
//            }
//        }
        //printf("%lld %lld\n",ans,res);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
16 5
2 4 5 3 2 8 10 10 11 8 2 20 21 22 23 5

*/
