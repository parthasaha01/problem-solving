#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll long long int
struct matrix
{
    ll v[5][5];
    int row,col;
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
    res.row=res.col=3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<3; i++)
    {
        res.v[i][i]=1;
    }

    for(ll i=p; i>0; i/=2)
    {
        if(i%2==1)
        {
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }
    return res;
    /*if(p==1) return mat;
    if(p%2==1){
        return multiply(mat,power(mat,p-1));
    }
    matrix ret;
    ret=power(mat,p/2);
    ret=multiply(ret,ret);
    return ret;*/
}
int main()
{
    ll n;

    while(scanf("%lld",&n) && n)
    {
        ll fn;

        if(n<=4)
        {
            if(n==1)
                fn=0;
            else if(n==2)
                fn=1;
            else if(n==3)
                fn=2;
            else{
                fn=3;
            }
        }
        else
        {
            matrix mat;
            mat.row=mat.col=3;
            mat.v[0][0]=mat.v[0][1]=mat.v[0][2]=mat.v[1][0]=mat.v[2][1]=1;
            mat.v[1][1]=mat.v[1][2]=mat.v[2][0]=mat.v[2][2]=0;

            mat=power(mat,n-4);
            fn = mat.v[0][0]*3;
            fn %= mod;
            fn += mat.v[0][1]*2;
            fn %= mod;
            fn += mat.v[0][2];
            fn %= mod;
        }
        printf("%lld\n",fn);
    }

    return 0;
}
