#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
//ll mod=18446744073709551616;
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
                //sum%=mod;
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
        if(i%2==1)
        {
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    ll p,q,n,T;
    ll ans,f1,f2;

    scanf("%llu",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%llu %llu %llu",&p,&q,&n);

        matrix mat;
        mat.row=mat.col=2;

        mat.v[0][0]=p;
        mat.v[0][1]=-q;
        mat.v[1][0]=1;
        mat.v[1][1]=0;

        f1=p;
        f2=(p*p)-(2*q);

        if(n<3)
        {
            if(n==0) ans=2;
            else if(n==1) ans=f1;
            else ans=f2;
        }
        else
        {
            mat=power(mat,n-2);
            ans=((f2*mat.v[0][0])+(f1*mat.v[0][1]));
        }
        printf("Case %d: %llu\n",test,ans);
    }

    return 0;
}
