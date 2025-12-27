#include<bits/stdc++.h>
using namespace std;
int a[10005],vis[100005];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(vis,0,sizeof(vis));

        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]=1;
        }

        int flag=1;

        for(int i=1;i<=n; i++)
        {
            if(vis[i]==0)
            {
                flag=0;
                printf("%d ",i);
            }
        }

        if(flag)printf("*");

        printf("\n");

    }
    return 0;
}
