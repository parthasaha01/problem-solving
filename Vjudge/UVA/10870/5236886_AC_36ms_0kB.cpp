#include<bits/stdc++.h>
using namespace std;
long int mod,a[25],f[25],d;
struct matrix
{
    long int v[25][25];
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
            long int sum=0;
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
matrix power(matrix mat, long int p)
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

    for(long int i=p; i>0; i/=2)
    {
        if(i%2==1)
            res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    long int n,m,T,ans;

    while(scanf("%ld %ld %ld",&d,&n,&m))
    {
        if(!d&&!n&&!m)
            break;
        mod=m;
        for(int i=0; i<d; i++){
            scanf("%ld",&a[i]);
            a[i]%=mod;
        }
        for(int i=d-1; i>=0; i--){
            scanf("%ld",&f[i]);
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
            base.v[0][i]=a[i];
        }
        for(int i=1;i<d;i++){
            base.v[i][i-1]=1;
        }

        if(n<=d)
        {
            ans=f[0];
        }
        else{
            base=power(base,n-d);
            ans=0;
            for(int i=0;i<d;i++)
            {
                ans+=f[i]*base.v[0][i];
                ans%=mod;
            }

        }


        printf("%ld\n",ans);
    }

    return 0;
}
