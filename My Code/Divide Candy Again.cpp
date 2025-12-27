#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
ll d;
struct matrix
{
    ll v[5][5];
    int row,col;
};
ll modulas(ll num)
{
    if(num>0) return num%mod;
    if(num==0) return 0;

    num = (-1)*num;
    ll mm = num%mod;
    if(mm==0) return 0;
    return mod-mm;
}
matrix multiply(matrix x, matrix y)
{
    matrix r;
    r.row=x.row;
    r.col=y.col;

    for(int i=0; i<r.row; i++){
        for(int j=0; j<r.col; j++){
            ll sum=0;
            for(int k=0; k<x.col; k++){
                sum+=x.v[i][k]*y.v[k][j];
                sum%=mod;
            }
            r.v[i][j]=sum;
        }
    }

    return r;
}
matrix power(matrix mat, ll p)
{
    matrix res;
    res.row=res.col=d;

    for(int i=0; i<d; i++)
        for(int j=0; j<d; j++)
            res.v[i][j]=0;

    for(int i=0; i<d; i++) res.v[i][i]=1;

    for(ll i=p; i>0; i/=2){
        if(i%2==1)
            res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll n; scanf("%lld",&n);

        matrix base;
        base.row = base.col = d = 3;

        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                base.v[i][j]=1;

        base.v[1][0] = base.v[2][0] = base.v[2][2] = 0;

        ll sn;

        if(n<=2)
        {
           if(n==1) sn = 1;
           else sn = 2;
        }
        else
        {
            base=power(base,n-2);
            sn = 2*base.v[0][0] + base.v[0][1] + base.v[0][2];
            sn %= mod;
        }

        ll ans = 2*sn;
        ans -= n;
        ans = modulas(ans);
        ans = 8*ans;
        ans %= mod;

        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}


