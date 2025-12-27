#include<bits/stdc++.h>
using namespace std;
//long long int a[25],f[25];
#define ll long long int
#define mod 1000000007
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

    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<3; i++){
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
    ll n,m,T,D,V,ans,f0;

    scanf("%lld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%lld %lld",&D,&V);

        matrix mat;
        mat.row=mat.col=3;

        mat.v[0][0]=1;
        mat.v[0][1]=0;
        mat.v[0][2]=V-1;
        mat.v[1][0]=1;
        mat.v[1][1]=0;
        mat.v[1][2]=0;
        mat.v[2][0]=0;
        mat.v[2][1]=0;
        mat.v[2][2]=V-1;

        if(D==0)
        {
            ans=1;
        }
        else if(V==1 && D>1)
        {
            ans=-1;
        }
        else
        {
            mat=power(mat,D);
            //printf("%lld %lld %lld %lld\n",mat.v[0][0],mat.v[0][1],mat.v[1][0],mat.v[1][1]);
            ans=((mat.v[0][2]%mod)+(mat.v[1][2]%mod)+2)%mod;
        }
        printf("Case %d: %lld\n",test,ans);
    }
    return 0;
}
