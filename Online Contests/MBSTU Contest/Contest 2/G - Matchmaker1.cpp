#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
//int b[1005][1005];
int dn[1005];
int dm[1005];
int main()
{
    int n,m,u,v,x,y;

    while(scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        memset(dn,0,sizeof(dn));
        memset(dm,0,sizeof(dm));

        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            a[x][y]++;
            dn[y]++;
        }
        v=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            //b[x][y]++;

            if(a[x][y]>0)
            {
                v++;
                a[x][y]--;
            }
            dm[y]++;
        }

        u=0;
        for(int i=1; i<=1000; i++)
        {
            u += min(dn[i],dm[i]);
        }

        printf("%d %d\n",u,v);
    }

    return 0;
}

