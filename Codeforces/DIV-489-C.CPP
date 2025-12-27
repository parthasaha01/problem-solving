#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007LL
struct Matrix
{
    ll v[2][2];
    int row,col;
};
ll BIGMOD(ll b,ll p)
{
    ll res = 1%MOD, x = b%MOD;
    while(p)
    {
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
Matrix multiply(Matrix x, Matrix y)
{
    Matrix r;
    r.row = x.row;
    r.col = y.col;

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ll sum=0;
            for(int k=0; k<x.col; k++)
            {
                sum += x.v[i][k]*y.v[k][j];
            }
            r.v[i][j]=sum%MOD;
        }
    }

    return r;
}
Matrix power(Matrix mat, ll p)
{
    Matrix res;
    res.row=res.col=2;

    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(ll i=p; i>0; i/=2)
    {
        if(i%2)
        {
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }

    return res;
}
int main()
{
    ll x,k;
    cin>>x>>k;

    if(x==0){
        cout << 0 << endl;
    }
    else if(k<1)
    {
        ll ans = ((2%MOD)*(x%MOD))%MOD;
        ans %= MOD;
        cout << ans << endl;
    }
    else
    {
        Matrix mat;
        mat.row=mat.col=2;
        mat.v[0][0]=4; mat.v[0][1]=-1;
        mat.v[1][0]=0; mat.v[1][1]=2;

        mat = power(mat,k);

        ll ans = 0;
        ans = ((mat.v[0][0]%MOD)*(x%MOD))%MOD;
        if(ans<0)ans = (ans+MOD)%MOD;
        ans += mat.v[0][1]%MOD;
        if(ans<0)ans = (ans+MOD)%MOD;
        ans %= MOD;
        ll ww = BIGMOD(2,k-1);
        ll pr = BIGMOD(ww,MOD-2);

        ans = ((ans%MOD)*(pr%MOD))%MOD;

        cout << ans << endl;
    }

    //main();

    return 0;
}



