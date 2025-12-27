#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mod 1000000007
struct matrix{
    LL v[5][5];
};
matrix multiply(matrix x, matrix y)
{
    matrix r;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            r.v[i][j] = 0;
            for(int k=0; k<2; k++){
                r.v[i][j] += x.v[i][k]*y.v[k][j];
                r.v[i][j] %= mod;
            }
        }
    }
    return r;
}
matrix power(matrix mat, LL p)
{
    matrix res;
    res.v[0][0]=res.v[1][1]=1;
    res.v[0][1]=res.v[1][0]=0;

    for(LL i=p; i>0; i/=2){
        if(i%2==1) res = multiply(res,mat);
        mat = multiply(mat,mat);
    }
    return res;
}
int main()
{
    int T; scanf("%d",&T);
    for(int ks=1; ks<=T; ks++)
    {
        LL n; scanf("%lld",&n);
        if(n==1){
            printf("Case %d: 3 3\n",ks); continue;
        }

        matrix mat;
        mat.v[0][0] = mat.v[0][1] = 1;
        mat.v[1][0] = 0;
        mat.v[1][1] = 4;

        mat = power(mat,n-1);

        LL f1 = 3, g1 = 3;
        LL fn = ((f1*mat.v[0][0])+(g1*mat.v[0][1]))%mod;
        LL gn = (g1*mat.v[1][1])%mod;
        printf("Case %d: %lld %lld\n",ks,fn,gn);
    }
    return 0;
}
