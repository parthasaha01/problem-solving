#include<bits/stdc++.h>
using namespace std;
int st[502][502][12],a[505][505];
int n;
void createSparseTable(int id)
{
    for(int i=1; i<=n; i++)st[id][i][0]=i;

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int x = st[id][i][j-1];
            int y = st[id][i+(1<<(j-1))][j-1];
            if(a[id][x]>=a[id][y])st[id][i][j]=x;
            else st[id][i][j]=y;
        }
    }
}
int query(int id,int i,int j)
{
    int k = (int)log2(j-i+1);
    int x = st[id][i][k];
    int y = st[id][j-(1<<k)+1][k];
    return max(a[id][x],a[id][y]);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        printf("Case %d:\n",ks);

        scanf("%d",&n);
        int q; scanf("%d",&q);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1; i<=n; i++)
        {
            createSparseTable(i);
        }

        while(q--)
        {
            int I,J,S;
            scanf("%d%d%d",&I,&J,&S);
            int maxx=0;
            for(int i=I; i<=I+S-1; i++)
            {
                int vv = query(i,J,J+S-1);
                maxx = max(maxx,vv);
            }
            printf("%d\n",maxx);
        }

    }
    return 0;
}
