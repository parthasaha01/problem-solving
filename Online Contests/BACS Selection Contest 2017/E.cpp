#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll d;
struct matrix
{
    ll v[11][11];
    ll row,col;
};
matrix multiply(matrix x, matrix y)
{
    matrix r;
    r.row=x.row;
    r.col=y.col;

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ll sum=0;
            for(int k=0; k<x.col; k++)
            {
                sum+=x.v[i][k]*y.v[k][j];
                if(sum>=mod)sum%=mod;
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
    {
        for(int j=0; j<d; j++)
        {
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<d; i++)
    {
        res.v[i][i]=1;
    }

    for(ll i=p; i>0; i/=2)
    {
        if(i%2==1)
            res = multiply(res,mat);
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

        ll fn;;

        if(n<k)
        {
           fn=1;
        }
        else
        {
            matrix mat;
            d=k;
            mat.row=mat.col=d;
            for(int i=0; i<d; i++){
                for(int j=0; j<d; j++){
                    mat.v[i][j]=0;
                }
            }

            mat.v[0][0]=mat.v[0][d-1]=1;
            for(int i=1; i<d; i++){
                mat.v[i][i-1]=1;
            }

            mat = power(mat,n-1);
            fn = mat.v[0][0]+mat.v[0][1];
            fn %= mod;
        }

        printf("Case %d: %lld\n",ks,fn);
    }

    return 0;
}



