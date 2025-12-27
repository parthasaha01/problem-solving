#include<bits/stdc++.h>
using namespace std;
#define mx 600000
int vis[mx+5];
int a[mx+5];
int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        memset(vis,0,sizeof(vis));
        int p1=0,p2=0;

        for(int i=1; i<=k; i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]=i;
        }

        if(vis[1]!=0)
        {
            p2=vis[1];
            if(a[1]!=1){
                p1=1;
            }
            else{
                p1=2;
            }

            printf("%d %d\n",p1,p2);
            continue;
        }

        bool flag=false;

        for(int i=1; i<=k; i++)
        {
            int v=a[i];
            int sq=sqrt(v);

            for(int x=2; x<=sq; x++)
            {
                if(v%x==0)
                {
                    int u=v/x;

                    if(vis[x]!=0)
                    {
                        p1=vis[v];
                        p2=vis[x];
                        flag=true;
                        break;
                    }
                    else if(vis[u]!=0)
                    {
                        p1=vis[v];
                        p2=vis[u];
                        flag=true;
                        break;
                    }
                }
            }

            if(flag){
                break;
            }

        }

        printf("%d %d\n",p1,p2);
    }

    return 0;
}
