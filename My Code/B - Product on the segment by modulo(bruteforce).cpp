#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mx 1000005
LL A[mx],B[mx],SZ[1005],BLOCK[1005],RANGE[1005][1005],tree[1005][4025];
LL N,Q,MOD,M,BLOCK_SIZE;
void BUILD(int i,int nd,int b,int e)
{
    if(b==e){
        tree[i][nd] = A[(i*BLOCK_SIZE)+b]%MOD;
        return;
    }

    int lf = 2*nd, rg = 2*nd+1, md=(b+e)/2;

    BUILD(i,lf,b,md);
    BUILD(i,rg,md+1,e);
    tree[i][nd] = (tree[i][lf]*tree[i][rg])%MOD;
}
LL query(int i,int nd,int b,int e,int x,int y)
{
    if(b>y || e<x)return 1LL;
    if(b>=x && e<=y)return tree[i][nd]%MOD;

    int lf = 2*nd, rg = 2*nd+1, md=(b+e)/2;

    LL p1 = query(i,lf,b,md,x,y)%MOD;
    LL p2 = query(i,rg,md+1,e,x,y)%MOD;
    return (p1*p2)%MOD;
}
void PRE_CALCULATION()
{
    for(int i=0; i<=BLOCK_SIZE; i++) BLOCK[i] = 1LL, SZ[i] = 0;

    for(int i=0; i<N; i++){
        BLOCK[i/BLOCK_SIZE] *= A[i];
        BLOCK[i/BLOCK_SIZE] %= MOD;
        SZ[i/BLOCK_SIZE]++;
    }

    for(int i=0; i<=BLOCK_SIZE; i++){
        for(int j=i; j<=BLOCK_SIZE; j++){
            if(i==j) RANGE[i][i] = BLOCK[i]%MOD;
            else{
                RANGE[i][j] = RANGE[i][j-1]*BLOCK[j];
                RANGE[j][i] = RANGE[i][j];
                RANGE[i][j] %= MOD;
                RANGE[j][i] %= MOD;
            }
        }
    }

    for(int i=0; i<=BLOCK_SIZE; i++){
        if(SZ[i]>0)BUILD(i,1,0,SZ[i]-1);
    }
}
LL solve(LL L,LL R)
{
    LL lb = L/BLOCK_SIZE;
    LL rb = R/BLOCK_SIZE;

    LL ans = 1LL;
    if(lb==rb){
        ans *= query(lb,1,0,SZ[lb]-1,L%BLOCK_SIZE,R%BLOCK_SIZE);
        ans %= MOD;
        return ans;
    }

    int xx = ((lb+1)*BLOCK_SIZE)-1;
    ans *= query(lb,1,0,SZ[lb]-1,L%BLOCK_SIZE,xx%BLOCK_SIZE);
    ans %= MOD;

    if(rb-lb>1){
        ans *= RANGE[lb+1][rb-1];
        ans *= MOD;
    }

    int yy = rb*BLOCK_SIZE;
    ans *= query(rb,1,0,SZ[rb]-1,yy%BLOCK_SIZE,R%BLOCK_SIZE);
    ans %= MOD;

    return ans;
}
//LL solve(LL L,LL R)
//{
//    LL lb = L/BLOCK_SIZE;
//    LL rb = R/BLOCK_SIZE;
//
//    LL ans = 1LL;
//    if(lb==rb){
//        for(int i=L; i<=R; i++){
//            ans *= A[i];
//            if(ans>=MOD)ans %= MOD;
//        }
//        return ans;
//    }
//
//    int xx = ((lb+1)*BLOCK_SIZE)-1;
//    for(int i=L; i<=xx; i++){
//        ans *= A[i];
//        if(ans>=MOD)ans %= MOD;
//    }
//
//    if(rb-lb>1){
//        for(int i=lb+1; i<rb; i++){
//            ans *= A[i];
//            if(ans>=MOD)ans %= MOD;
//        }
//    }
//
//    int yy = rb*BLOCK_SIZE;
//    for(int i=yy; i<=R; i++){
//        ans *= A[i];
//        if(ans>=MOD)ans %= MOD;
//    }
//
//    return ans;
//}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%lld %lld %lld",&N,&MOD,&Q);
        for(int i=0; i<N; i++){
            scanf("%lld",&A[i]);
        }

        BLOCK_SIZE = sqrt(N)+1;

        PRE_CALCULATION();

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

            cout << "l=" << L << " " << "r=" << R << endl;

            //ans = fun(L,R);

            ans = solve(L,R)%MOD;

            x = (ans+1)%MOD;

            cout << "ans=" << ans << " " << "x=" << x << endl << endl;
        }

        ans = x;
        printf("%lld\n",ans);
    }
    return 0;
}
/*

2
6 113 3
1 2 3 4 5 6
1 4
l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

8
6 113 70
1 2 3 4 5 6
1 4 3
l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=1 r=4
ans=7 x=8

l=0 r=3
ans=24 x=25

l=4 r=5
ans=30 x=31

l=0 r=5
ans=42 x=43

l=0 r=1
ans=2 x=3

l=3 r=4
ans=20 x=21

l=0 r=1
ans=2 x=3

l=3 r=4
ans=20 x=21

21
*/
