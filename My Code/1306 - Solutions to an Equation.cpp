#include<bits/stdc++.h>
using namespace std;
int ext_gcd ( int A, int B, int *X, int *Y )
{
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for( r2=A,r1=B; r1!=0; r2=r1,r1=r,x2=x1,y2=y1,x1=x,y1=y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
bool linearDiophantine ( int A, int B, int C, int *x, int *y )
{
    int g = __gcd (A, B);
    if( C % g != 0 ) return false; //No Solution

    int a = A / g, b = B / g, c = C / g;

    ext_gcd(a, b, x, y); //Solve ax + by = 1

    if(g < 0)
    { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }

    *x *= c; *y *= c; //ax + by = c

    return true; //Solution Exists
}
int solve(int A,int B,int C,int X1,int X2,int Y1,int Y2)
{
    int x, y, ans = 0;

    bool res = linearDiophantine ( A, B, C, &x, &y);

    if ( res == false ) ans = 0;
    else
    {
        printf ( "One Possible Solution (%d %d) \n", x, y );
        int g = __gcd (A, B);
        int a = A / g, b = B / g;
        int kx1 = (X1-x)/b;
        int kx2 = (X2-x)/b;
        int ky1 = (y-Y1)/a;
        int ky2 = (y-Y2)/a;

        int kx = max(kx1,ky2);
        int ky = min(kx2,ky1);

        printf("kx1=%d kx2=%d ky1=%d ky2=%d kx=%d ky=%d\n",kx1,kx2,ky1,ky2,kx,ky);

        if(ky<kx)ans=0;
        else ans = (ky-kx)+1;
    }

    return ans;
}
int main ()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        //printf("%d\n",__gcd(-10,-8));
        int A,B,C,X1,X2,Y1,Y2;
        scanf("%d%d%d%d%d%d%d",&A,&B,&C,&X1,&X2,&Y1,&Y2);

        int ans = solve(A,B,C,X1,X2,Y1,Y2);
        printf("Case %d: %d\n",ks,ans);

        for(int i=X1; i<=X2; i++)
        {
            for(int j=Y1; j<=Y2; j++)
            {
                if(A*i+B*j+C==0){
                    printf("(%d %d)\n",i,j);
                }
            }
        }
    }

    return 0;
}
