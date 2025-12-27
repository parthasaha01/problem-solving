#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int dn[1001];
int dm[1001];
int main()
{
    int n,m,u,v,x,y;

    scanf("%d%d",&n,&m);


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

    return 0;
}
