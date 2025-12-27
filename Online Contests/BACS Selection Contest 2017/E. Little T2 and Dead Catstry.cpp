#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
struct matrix
{
    ll v[2][2];
    ll row,col;
};
matrix multiply(matrix x, matrix y)
{
    matrix r;
    r.row = x.row;
    r.col = y.col;

    for(ll i=0; i<r.row; i++)
    {
        for(ll j=0; j<r.col; j++)
        {
            ll sum=0;
            for(ll k=0; k<x.col; k++)
            {
                sum += x.v[i][k]*y.v[k][j];
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

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll k,n;
        scanf("%lld%lld",&k,&n);

        ll f0,f1,fn;
        f0=0;
        f1=1;

        if(n<k)
        {
           //printf("Case %d: 1\n",ks);
           fn=1;
        }
        else if(k==2)
        {
            matrix mat;
            mat.row=mat.col=2;
            mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
            mat.v[1][1]=0;

            mat = power(mat,n-k+1);
            fn = mat.v[0][0]+mat.v[0][1];
            fn %= mod;
        }
        else
        {

        }

        printf("Case %d: %lld\n",ks,fn);
    }

    return 0;
}


