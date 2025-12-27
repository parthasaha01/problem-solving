#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mx 1000005
struct data{
    vector<LL> left;
    vector<LL> right;
};
data ST[4*mx];
LL A[mx],B[mx];
LL N,Q,MOD,M;

void BUILD(int nd,int b,int e)
{
    if(b==e){
        ST[nd].left.assign(1,A[b]);
        return;
    }

    int lf = 2*nd, rg = 2*nd+1, md=(b+e)/2;

    ST[nd].left.resize(md-b+1);
    ST[nd].right.resize(e-md);

    ST[nd].left[0] = A[md];
    for(int i=md-1,j=1; i>=b; i--,j++){
        ST[nd].left[j] = (ST[nd].left[j-1]*A[i])%MOD;
    }

    if(e>md){
        ST[nd].right[0] = A[md+1];
        for(int i=md+2,j=1; i<=e; i++,j++){
            ST[nd].right[j] = (ST[nd].right[j-1]*A[i])%MOD;
        }
    }

    BUILD(lf,b,md);
    BUILD(rg,md+1,e);
}
LL query(int nd,int b,int e,int x,int y)
{
    int lf = 2*nd, rg = 2*nd+1, md=(b+e)/2;

    if(x<=md && md<=y){
        LL ans = 1LL;
        ans = ST[nd].left[md-x];
        if(y>md){
            ans *= ST[nd].right[y-md-1];
            ans %= MOD;
        }
        return ans%MOD;
    }

    if(b<=x && y<=md)return query(lf,b,md,x,y);
    else return query(rg,md+1,e,x,y);

}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lld %lld %lld",&N,&MOD,&Q);
        for(int i=0; i<N; i++){
            scanf("%lld",&A[i]);
        }

        BUILD(1,0,N-1);

        M = (Q/64)+2;
        for(int i=0; i<M; i++){
            scanf("%lld",&B[i]);
        }

        LL ans,x = 0;
        LL L=0,R=0;

        for(int i=0; i<Q; i++)
        {
            if(i%64==0){
                L = (B[i/64]+x)%N;
                R = (B[(i/64)+1]+x)%N;
                if(L>R)swap(L,R);
            }
            else{
                L = (L+x)%N;
                R = (R+x)%N;
                if(L>R)swap(L,R);
            }

            ans = query(1,0,N-1,L,R)%MOD;
            x = (ans+1)%MOD;
        }

        ans = x;
        printf("%lld\n",ans);
    }

    return 0;

}
