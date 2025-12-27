#include<bits/stdc++.h>
using namespace std;
#define inf 0x7f7f7f7f

int mn[555][32][555], mx[555][32][555];
int MN, MX, a[555][555];

void SparseTable(int n, int m)
{
    int lg=log2(n);
    for(int i=1;i<=n;i++) mn[m][0][i] = mx[m][0][i] = a[m][i];

    for(int i=1; i<=lg; i++)
    {
        int add = 1<<(i-1);
        for(int j=1; j<=n-add;j++)
        {
            mn[m][i][j] = min(mn[m][i-1][j],mn[m][i-1][j+add]);
            mx[m][i][j] = max(mx[m][i-1][j],mx[m][i-1][j+add]);
        }
    }
}

void Find(int s, int t, int x, int y)
{
    int m;
    int lg = log2(y-x+1);
    int add = 1<<lg;
    for(m=s;m<=t;m++)
    {
        MX = max(MX,max(mx[m][lg][x],mx[m][lg][y-add+1]));
        MN = min(MN,min(mn[m][lg][x],mn[m][lg][y-add+1]));
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);

            SparseTable(n,i);
        }

        int q; scanf("%d",&q);
        while(q--)
        {
            int r1,c1,r2,c2;
            char ch;
            getchar();
            scanf("%c%d%d%d",&ch,&r1,&c1,&r2);
            if(ch=='c'){
                a[r1][c1] = r2;
                SparseTable(n,r1);
            }
            else{
                scanf("%d",&c2);
                MX=-1; MN=inf;
                Find(r1,r2,c1,c2);
                printf("%d %d\n",MX,MN);
            }
        }
    }
    return 0;
}
/*
5
1 2 3 4 5
0 9 2 1 3
0 2 3 4 1
0 1 2 4 5
8 5 3 1 4
4
q 1 1 2 3
c 2 3 10
q 1 1 5 5
q 1 2 2 2
*/
