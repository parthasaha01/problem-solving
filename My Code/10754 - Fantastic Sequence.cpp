#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod,d,c[25],a[25];
ll modulas(ll num, ll mod)  // modulas of negetive number
{
    if(num>0)
        return num%mod;
    if(num==0)
        return 0;

    num = -num;
    ll M = num%mod;

    if(M==0)
        return 0;
    return mod-M;
}
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
                sum=modulas(sum,mod);
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
    ll t;
    scanf("%lld",&t);

    for(int kase=1; kase<=t; kase++)
    {
        ll k,m,n,an;

        scanf("%lld%lld%lld",&k,&m,&n);

        mod=m;
        d=k+1;

        for(int i=1; i<=d; i++)
        {
            scanf("%lld",&c[i]);
            c[i]=modulas(c[i],mod);
        }
        for(int i=0; i<k; i++)
        {
            scanf("%lld",&a[i]);
            a[i]=modulas(a[i],mod);
        }


        if(n<k)
        {
            an=a[n];
        }
        else
        {
            matrix base;
            base.row=base.col=d;

            for(int i=0; i<d; i++){
                for(int j=0; j<d; j++){
                    base.v[i][j]=0;
                }
            }

            for(int i=0; i<k; i++){
                base.v[0][i] = c[i+1];
            }

            base.v[0][k]=1;
            for(int i=1; i<k; i++){
                base.v[i][i-1]=1;
            }
            base.v[k][k]=1;

            /*for(int i=0; i<d; i++){
                for(int j=0; j<d; j++){
                    printf("%lld ",base.v[i][j]);
                }
                printf("\n");
            }*/

            base=power(base,n-k+1);

            /*printf("\n");
            for(int i=0; i<d; i++){
                for(int j=0; j<d; j++){
                    printf("%lld ",base.v[i][j]);
                }
                printf("\n");
            }*/

            an=0;
            for(int i=0; i<k; i++)
            {
                an+=base.v[0][i]*a[k-i-1];
                an=modulas(an,mod);
            }
            an+=base.v[0][k]*c[k+1];
            an=modulas(an,mod);
        }


        printf("%lld\n",an);
        if(kase<t)
            printf("\n");
    }

    return 0;
}
