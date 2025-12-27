#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int d,mod;
struct matrix
{
    int v[6][6];
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
            int sum=0;
            for(int k=0; k<x.col; k++)
            {
                sum += x.v[i][k]*y.v[k][j];
                sum %= mod;
            }
            r.v[i][j]=sum;
        }
    }

    return r;
}
matrix power(matrix mat,int p)
{
    matrix res;
    res.row=res.col=d;

    for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            res.v[i][j]=0;
        }
    }

    for(int i=0; i<d; i++){
        res.v[i][i]=1;
    }

    for(int i=p; i>0; i/=2)
    {
        if(i%2==1){
            res = multiply(res,mat);
        }
        mat = multiply(mat,mat);
    }

    return res;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int a1,b1,c1,a2,b2,c2;
        int f[3],g[3];

        scanf("%d%d%d",&a1,&b1,&c1);
        scanf("%d%d%d",&a2,&b2,&c2);
        scanf("%d%d%d",&f[0],&f[1],&f[2]);
        scanf("%d%d%d",&g[0],&g[1],&g[2]);

        scanf("%d",&mod);
        for(int i=0; i<3; i++){
            f[i]%=mod;
            g[i]%=mod;
        }

        int q;
        scanf("%d",&q);

        printf("Case %d:\n",kase);
        for(int i=0; i<q; i++)
        {
            int n;
            scanf("%d",&n);

            matrix base;
            d=base.row=base.col=6;

            for(int x=0; x<base.row; x++){
                for(int y=0; y<base.col; y++){
                    base.v[x][y]=0;
                }
            }
            base.v[0][0]=a1%mod;
            base.v[0][1]=b1%mod;
            base.v[0][5]=c1%mod;
            base.v[3][2]=c2%mod;
            base.v[3][3]=a2%mod;
            base.v[3][4]=b2%mod;
            base.v[1][0]=base.v[2][1]=base.v[4][3]=base.v[5][4]=1;

            int fn=0,gn=0;

            if(n<3){
                fn=f[n]%mod;
                gn=g[n]%mod;
            }
            else
            {
                base = power(base,n-2);

                fn = ((base.v[0][0]*f[2]) + (base.v[0][1]*f[1]) + (base.v[0][2]*f[0]) + (base.v[0][3]*g[2]) + (base.v[0][4]*g[1]) + (base.v[0][5]*g[0]))%mod;
                gn = ((base.v[3][0]*f[2]) + (base.v[3][1]*f[1]) + (base.v[3][2]*f[0]) + (base.v[3][3]*g[2]) + (base.v[3][4]*g[1]) + (base.v[3][5]*g[0]))%mod;

            }

            printf("%d %d\n",fn,gn);
        }

    }

    return 0;
}
