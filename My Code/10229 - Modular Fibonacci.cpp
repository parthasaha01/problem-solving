#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int mod;
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
                sum%=mod;
            }
            r.v[i][j]=sum;
        }
    }

    return r;
}
matrix power(matrix mat, int p)
{
    matrix res;
    res.row=res.col=2;

    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(int i=p; i>0; i/=2)
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
    int n,m;

    while(scanf("%d%d",&n,&m)==2)
    {
        mod=1;
        int num=2;
        for(int i=m; i>0; i/=2)
        {
            if(i%2){
                mod *= num;
            }
            num *= num;
        }

        ll f0,f1,fn;
        f0=0;
        f1=1;

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
            mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
            mat.v[1][1]=0;

            mat = power(mat,n-1);
            fn = mat.v[0][0];
        }
        printf("%lld\n",fn);
    }

    return 0;
}

