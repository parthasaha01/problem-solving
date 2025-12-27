#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
        if(i%2){
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }

    return res;
}
int main()
{
    ll n,p,q;
    char ch;

    while(1)
    {
        scanf("%lld%lld%c",&p,&q,&ch);
        if(ch=='\n')
        {
            if(p==0&&q==0){
                break;
            }
        }
        scanf("%lld",&n);

        ll f0,f1,fn;

        f0=2;
        f1=p;

        if(n<2)
        {
            if(n==0){
                fn=f0;
            }
            else{
                fn=f1;
            }
        }
        else
        {
            matrix mat;
            mat.row=mat.col=2;
            mat.v[0][0]=p;
            mat.v[0][1]=-q;
            mat.v[1][0]=1;
            mat.v[1][1]=0;

            mat = power(mat,n-1);
            //fn = ((mat.v[0][0]*f1)%mod + (mat.v[0][1]*f0)%mod);
            fn = mat.v[0][0]*f1 + mat.v[0][1]*f0;
        }

        printf("%lld\n",fn);
    }

    return 0;
}
