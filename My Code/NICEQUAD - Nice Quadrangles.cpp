#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[4], B[4], C[4], D[4];
int ptIdx(int x, int y)
{
    x = abs(x); y = abs(y);
    if((x%2==0) && (y%2==0))return 0;
    if((x%2==1) && (y%2==0))return 1;
    if((x%2==0) && (y%2==1))return 2;
    if((x%2==1) && (y%2==1))return 3;
}

bool isNiceQuad(int a, int b, int c, int d)
{
    int g1,g2,g3,g4;

    if(a==b) g1 = 0;
    else g1 = 1;

    if(b==c) g2 = 0;
    else g2 = 1;

    if(c==d) g3 = 0;
    else g3 = 1;

    if(d==a) g4 = 0; // GCD is even
    else g4 = 1;     // GCD is odd

    int I = g1^g2^g3^g4;

    if(I%2==0) return 1;
    else return 0;
}

int main()
{
    int t; scanf("%d",&t);
    for (int ks=1; ks <= t; ks++)
    {
        int n; scanf("%d",&n);

        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
        memset(D, 0, sizeof(D));

        for(int i=0; i < n; ++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            if(x>0 && y>0) A[ptIdx(x,y)]++; // First Quadrant
            if(x>0 && y<0) B[ptIdx(x,y)]++; // Fourth Quadrant
            if(x<0 && y<0) C[ptIdx(x,y)]++; // Third Quadrant
            if(x<0 && y>0) D[ptIdx(x,y)]++; // Second Quadrant
        }

        ll numQuads = 0;

        for(int a=0; a<4; a++){
            for(int b=0; b<4; b++){
                for(int c=0; c<4; c++){
                    for(int d=0; d<4; d++){
                        if(isNiceQuad(a,b,c,d)){
                            ll comb=(ll)(A[a]*B[b])*(ll)(C[c]*D[d]);
                            numQuads += comb;
                        }
                    }
                }
            }
        }

        printf("%lld\n",numQuads);
    }
    return 0;
}

