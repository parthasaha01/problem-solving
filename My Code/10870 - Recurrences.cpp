#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod,a[25],f[25],d;
struct matrix
{
    ll v[25][25];
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
    res.row=res.col=d;

    for(int i=0; i<d; i++){
        for(int j=0;j<d;j++){
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<d; i++){
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
    ll n,m;

    while(scanf("%lld %lld %lld",&d,&n,&m))
    {
        if(!d&&!n&&!m)
            break;

        mod=m;

        for(int i=1; i<=d; i++){
            scanf("%lld",&a[i]);
            a[i]%=mod;
        }
        for(int i=1; i<=d; i++){
            scanf("%lld",&f[i]);
            f[i]%=mod;
        }

        matrix base;
        base.row=base.col=d;

        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                base.v[i][j]=0;
            }
        }
        for(int i=0;i<d;i++){
            base.v[0][i]=a[i+1];
        }
        for(int i=1;i<d;i++){
            base.v[i][i-1]=1;
        }

        ll fn;

        if(n<=d)
        {
            fn=f[n];
        }
        else
        {
            base=power(base,n-d);

            fn=0;

            for(int i=0;i<d;i++)
            {
                fn+=base.v[0][i]*f[d-i];
                fn%=mod;
            }

        }


        printf("%lld\n",fn);
    }

    return 0;
}

