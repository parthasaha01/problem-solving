#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int n,ff[mx+5],gg[mx+5],hh[mx+5],vis[mx+5];
int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(vis,false,sizeof(vis));
        int cnt=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&ff[i]);
            if(!vis[ff[i]])cnt++;
            vis[ff[i]]=1;
        }

        int m = cnt;



        printf("%d\n",m);
        for(int i=1; i<=n; i++){
            if(i==n)printf("%d\n",gg[i]);
            else printf("%d ",gg[i]);
        }
        for(int i=1; i<=m; i++){
            if(i==m)printf("%d\n",hh[i]);
            else printf("%d ",hh[i]);
        }
    }

    return 0;
}
