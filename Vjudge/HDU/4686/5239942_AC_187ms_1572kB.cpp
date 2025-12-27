#include<bits/stdc++.h>
using namespace std;
//long long int a[25],f[25];
#define mod 1000000007
struct matrix
{
    unsigned long long int v[10][10];
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
            unsigned long long int sum=0;
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
matrix power(matrix mat, unsigned long long int p)
{
    matrix res;
    res.row=res.col=5;

    for(int i=0; i<5; i++){
        for(int j=0;j<5;j++){
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<5; i++){
        res.v[i][i]=1;
    }

    for(unsigned long long int i=p; i>0; i/=2)
    {
        if(i%2==1)
            res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    unsigned long long int n,m,T,ans,a0,b0,ax,bx,ay,by,f0,f1;

    while(scanf("%llu",&n)==1)
    {
        scanf("%llu %llu %llu",&a0,&ax,&ay);
        scanf("%llu %llu %llu",&b0,&bx,&by);

        matrix base;
        base.row=base.col=5;

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                base.v[i][j]=0;
            }
        }

        base.v[0][0]=base.v[4][4]=1;
        base.v[2][0]=base.v[2][1]=(ax*by)%mod;
        base.v[3][0]=base.v[3][1]=(bx*ay)%mod;
        base.v[1][0]=base.v[1][1]=(ax*bx)%mod;
        base.v[4][0]=base.v[4][1]=(ay*by)%mod;
        base.v[2][2]=ax;
        base.v[3][3]=bx;
        base.v[4][2]=ay;
        base.v[4][3]=by;

        f0=0;

        f1=(a0*b0)%mod;

        if(n==0)
        {
            ans=0;
        }
        else if(n==1)
        {
            ans=f1;
        }
        else{
            base=power(base,n-1);
            ans=0;
                ans=(ans+(base.v[0][0]*f1)%mod)%mod;
                ans=(ans+(base.v[1][0]*f1)%mod)%mod;
                ans=(ans+(base.v[2][0]*a0)%mod)%mod;
                ans=(ans+(base.v[3][0]*b0)%mod)%mod;
                ans=(ans+base.v[4][0]%mod)%mod;
                ans%=mod;

        }

        printf("%llu\n",ans);
    }

    return 0;
}
