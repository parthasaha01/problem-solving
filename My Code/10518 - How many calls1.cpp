#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,b;
struct matrix
{
    ll v[3][3];
    int row,col;
};
matrix multiply(matrix x, matrix y)
{
    matrix r;
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
            r.v[i][j]=sum%b;
        }
    }

    return r;
}
matrix power(matrix mat, ll p)
{
    matrix res;
    res.row=res.col=3;

    res.v[0][0]=res.v[1][1]=res.v[2][2]=1;
    res.v[0][1]=res.v[0][2]=res.v[1][0]=res.v[1][2]=res.v[2][0]=res.v[2][1]=0;

    for(ll i=p; i>0; i/=2)
    {
        if(i%2) res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    int ks=0;

    while(scanf("%lld%lld",&n,&b)==2)
    {
        if(n==0&&b==0)break;

        ll f0,f1,fn;
        f0=1; f1=1;

        if(n<2)
        {
            if(n==0)fn=f0;
            else fn=f1;
        }
        else
        {
            matrix mat;
            mat.row=mat.col=3;
            mat.v[0][0]=mat.v[0][1]=mat.v[0][2]=mat.v[1][0]=mat.v[2][2]=1;
            mat.v[1][1]=mat.v[1][2]=mat.v[2][0]=mat.v[2][1]=0;

            mat = power(mat,n-1);
            fn = mat.v[0][0]*f1+mat.v[0][1]*f0+mat.v[0][2];
        }

        fn = fn%b;

        printf("Case %d: %lld %lld %lld\n",++ks,n,b,fn);
    }

    return 0;
}
/*
9223372036854775806 10000

*/



