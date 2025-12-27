#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    double v[2][2];
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
            double sum=0.0;
            for(int k=0; k<x.col; k++)
            {
                sum += x.v[i][k]*y.v[k][j];
            }
            r.v[i][j]=sum;
        }
    }

    return r;
}
matrix power(matrix mat, int p)
{
    matrix res;
    res.row=res.col=2;

    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(int i=p; i>0; i/=2)
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
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n;
        double f0,f1,fn,a,b;
        scanf("%lf%lf%lf%lf%d",&f0,&f1,&a,&b,&n);

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
            mat.v[0][0]=a;
            mat.v[0][1]=b;
            mat.v[1][0]=1;
            mat.v[1][1]=0;

            mat = power(mat,n-1);
            fn = mat.v[0][0]*f1 + mat.v[0][1]*f0;
        }
        printf("%.0lf\n",fn);
    }

    return 0;
}
