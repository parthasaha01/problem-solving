#include<bits/stdc++.h>
using namespace std;
int md[]={1,10,100,1000,10000};
int mod;
struct matrix
{
    long int v[5][5];
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
    res.row=res.col=2;
    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(long int i=p; i>0; i/=2)
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
    long int a,b,n,m,T,ans;

    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%ld %ld %ld %ld",&a,&b,&n,&m);

        mod=md[m];
        a%=mod;
        b%=mod;

        matrix mat;
        mat.row=mat.col=2;
        mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
        mat.v[1][1]=0;

        if(n<3)
        {
            if(n==0) ans=a;
            else if(n==1) ans=b;
            else ans=(a+b)%mod;
        }
        else
        {
            mat=power(mat,n-1);
            ans=((b*mat.v[0][0])+(a*mat.v[0][1]))%mod;
        }
        printf("Case %d: %ld\n",test,ans);
    }

    return 0;
}
