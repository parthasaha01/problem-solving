#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 4294967296
ll c[60][60],d;
struct matrix
{
    ll v[55][55];
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
void ncr()
{
    memset(c,0,sizeof(c));
    for(int i=0; i<55; i++)
    {
        c[i][0]=1;
    }
    for(int i=1; i<55; i++)
    {
        for(int j=1; j<=i; j++)
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            c[i][j] %= mod;
        }
    }
}
int main()
{
    ncr();

    /*for(int i=0; i<53; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("%dC%d=%lld\n",i,j,c[i][j]);
        }
        printf("\n");
    }*/

    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        d=k+2;
        ll fn=0;

        if(n==1)
        {
            fn=1;
        }
        else
        {
            matrix mat;
            mat.row=mat.col=d;

            for(int i=0; i<d; i++)
            {
                for(int j=0; j<d; j++)
                {
                    mat.v[i][j]=0;
                }
            }

            for(int i=0; i<d; i++)
            {
                mat.v[i][i]=1;
            }

            for(int i=1; i<d; i++)
            {
                mat.v[0][i]=c[k][i-1];
            }

            for(int i=1,x=k; i<=k; i++,x--)
            {
                for(int j=i+1,y=1; j<d; j++,y++)
                {
                    mat.v[i][j]=c[x][y];
                }
            }

            /*for(int i=0; i<d; i++)
            {
                for(int j=0; j<d; j++)
                {
                    printf("%lld ",mat.v[i][j]);
                }
                printf("\n");
            }*/

            mat = power(mat,n-1);

            /*for(int i=0; i<d; i++)
            {
                for(int j=0; j<d; j++)
                {
                    printf("%lld ",mat.v[i][j]);
                }
                printf("\n");
            }*/

            for(int i=0; i<d; i++){
                fn += mat.v[0][i];
                fn %= mod;
            }
        }

        printf("Case %d: %lld\n",kase,fn);
    }

    return 0;
}
