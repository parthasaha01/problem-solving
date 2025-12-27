#include<bits/stdc++.h>
using namespace std;
int n,row,col,maxx;
int a[80][80],b[155][155],c[155][155],v[155],kd[155];
int fun()
{
    int rw=row+row;
    int cl=col+col;

    for(int i=1,x=1; i<=rw; i++,x++)
    {
        if(x>row)x=1;
        for(int j=1,y=1; j<=cl; j++,y++)
        {
            if(y>col)y=1;
            b[i][j] = a[x][y];
        }
    }

    for(int i=1; i<=cl; i++)
    {
        for(int j=1; j<=rw; j++)
        {
            c[i][j]=c[i][j-1]+b[j][i]; // be careful for b[j][i]
        }
    }

    int ans=maxx;

    for(int i=1; i<=row; i++)
    {
        for(int j=i; j<=row+i-1; j++)
        {
            for(int k=1; k<=cl; k++)
            {
                v[k] = c[k][j]-c[k][i-1];
            }

            for(int x=1,kk=0; x<=cl; x++) // kadane or 1D maximum sum
            {
                kd[x]=kd[x-1]+v[x];
                kk++;

                if(kd[x]<0)
                {
                    kd[x]=0;
                    kk=0;
                }
                else
                {
                    ans = max(ans,kd[x]);

                    if(kk==col)
                    {
                        kk--;
                        int p = x-col+1;
                        kd[x] -= v[p];
                        p++;

                        int mx=kd[x];
                        int mp=p;

                        while(p<=x)
                        {
                            kd[x] -= v[p];
                            p++;
                            kk--;
                            if(kd[x]>=mx)
                            {
                                mx=kd[x];
                                mp=p;
                            }
                        }

                        kd[x]=mx;
                        kk = (x-mp)+1;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    int tt; scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d",&n);
        row=col=n;
        maxx=-100000;
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                scanf("%d",&a[i][j]);
                maxx = max(maxx,a[i][j]);
            }
        }

        int ans = fun();

        printf("%d\n",ans);
    }
    return 0;
}
/*
3

10

 92  94 -13 -40 -19  21 -75  82  87  45
-56  96 -84 -54  -5  44 -46  68  48  31
-93 -56  76 -12 -11  99 -57  27 -40 -46
-76  43   3 -62 -53 -52  89  19 -82  64
 97  71  36  15 -51  76 -38 100  64 -95
 63  14 -38 -94 -49 -49 -82 -70 -83 -23
 87  86  80  -3  37 -71  89 -50 -92  37
 10  73  67  81 -42  30 -50 -15 -57  64
-21 -83 -72  69 -67 -56 -47 -42 -42 -36
 66  74   0   5 -25 -52 -16  67 -41  49

5
1 2 4 3 -3
-1 3 1 -2 2
0 -2 -1 1 4
0 -3 5 -3 1
-4 2 0 2 -4

4
1 0 0 1
0 -1 -1 0
0 4 -1 0
1 0 0 2

*/
