#include<bits/stdc++.h>
using namespace std;
#define mod 10007
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
    res.row=res.col=4;
    for(int i=0; i<4; i++){
        for(int j=0;j<4;j++){
            res.v[i][j]=0;
        }
    }
    for(int i=0; i<4; i++){
        res.v[i][i]=1;
    }

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
    long int a,b,c,n,m,T,ans;

    scanf("%ld",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%ld %ld %ld %ld",&n,&a,&b,&c);

        a%=mod;
        b%=mod;
        c%=mod;

        matrix mat;
        mat.row=mat.col=4;
        mat.v[0][0]=a;
        mat.v[0][2]=b;
        mat.v[0][1]=mat.v[1][1]=mat.v[1][2]=mat.v[1][3]=mat.v[2][0]=0;
        mat.v[2][2]=mat.v[2][3]=mat.v[3][0]=mat.v[3][1]=mat.v[3][2]=0;
        mat.v[0][3]=mat.v[1][0]=mat.v[2][1]=mat.v[3][3]=1;

        if(n<3)
        {
            ans=0;
        }
        else
        {
            mat=power(mat,n-2);
            ans=(mat.v[0][3]*c)%mod;
        }
        printf("Case %d: %ld\n",test,ans);
    }

    return 0;
}

