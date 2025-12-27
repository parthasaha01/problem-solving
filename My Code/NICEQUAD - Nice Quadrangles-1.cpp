#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[4], B[4], C[4], D[4];
int ptIdx(int x, int y)
{
    return ((y & 1) << 1) | (x & 1);
}

bool isNiceQuad(int a, int b, int c, int d)
{
    int g1 = a ^ b;
    g1 = (g1 >> 1) & g1;
    int g2 = b ^ c;
    g2 = (g2 >> 1) & g2;
    int g3 = c ^ d;
    g3 = (g3 >> 1) & g3;
    int g4 = d ^ a;
    g4 = (g4 >> 1) & g4;

    int I = g1^g2^g3^g4;

    return (I & 1) == 0;
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
            int x,y; scanf("%d%d",&x,&y);

            if(x>0 && y>0) A[ptIdx(x,y)]++; // First Quadrant
            if(x>0 && y<0) B[ptIdx(x,y)]++; // Fourth Quadrant
            if(x<0 && y<0) C[ptIdx(x,y)]++; // Third Quadrant
            if(x<0 && y>0) D[ptIdx(x,y)]++; // Second Quadrant
        }

        ll numQuads = 0;

        for(int a=0; a<4; a++)
        {
            for(int b=0; b<4; b++)
            {
                for(int c=0; c<4; c++)
                {
                    for(int d=0; d<4; d++)
                    {
                        if(isNiceQuad(a,b,c,d))
                        {
                            ll comb = (ll)(A[a] * B[b]) * (ll)(C[c] * D[d]);
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

