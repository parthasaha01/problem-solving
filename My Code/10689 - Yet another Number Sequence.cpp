#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ma[]={0,10,100,1000,10000};
ll mod;
struct matrix
{
    ll v[2][2];
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
            r.v[i][j]=sum%mod;
        }
    }

    return r;
}
matrix power(matrix mat, ll p)
{
    matrix res;
    res.row=res.col=2;

    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(ll i=p; i>0; i/=2)
    {
        if(i%2){
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }

    return res;
}
int main()
{
    int t;

    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        ll a,b,n,m;

        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);

        ll f0,f1,fn;

        f0=a;
        f1=b;
        mod=ma[m];

        if(n<2)
        {
            if(n==0){
                fn=f0%mod;
            }
            else{
                fn=f1%mod;
            }
        }
        else
        {
            matrix mat;
            mat.row=mat.col=2;
            mat.v[0][0]=1;
            mat.v[0][1]=1;
            mat.v[1][0]=1;
            mat.v[1][1]=0;

            mat = power(mat,n-1);
            //fn = ((mat.v[0][0]*f1)%mod + (mat.v[0][1]*f0)%mod);
            fn = mat.v[0][0]*f1 + mat.v[0][1]*f0;
            fn = fn%mod;
        }

        printf("%lld\n",fn);
    }

    return 0;
}
