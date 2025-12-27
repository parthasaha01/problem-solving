#include<bits/stdc++.h>
using namespace std;
int a[10],b[10],c[10];
int vis[10005];
int main()
{
    int n; scanf("%d",&n);

    memset(vis,0,sizeof(vis));

    if(n==1)
    {
        for(int i=1; i<=6; i++){
            scanf("%d",&a[i]);
        }

        for(int i=1; i<=6; i++){
            vis[a[i]]=1;
        }

        int ans = 0;
        for(int i=1; i<=9; i++)
        {
            if(vis[i]==0)
            {
                break;
            }
            ans++;
        }

        printf("%d\n",ans);
    }
    else if(n==2)
    {
        for(int i=1; i<=6; i++){
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=6; i++){
            scanf("%d",&b[i]);
        }

        for(int i=1; i<=6; i++){
            vis[a[i]]=1;
        }
        for(int i=1; i<=6; i++){
            vis[b[i]]=1;
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (a[i]*10)+b[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (b[i]*10)+a[j];
                vis[v]=1;
            }
        }

        int ans = 0;
        for(int i=1; i<=99; i++)
        {
            if(vis[i]==0)
            {
                break;
            }
            ans++;
        }

        printf("%d\n",ans);

    }
    else
    {
        for(int i=1; i<=6; i++){
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=6; i++){
            scanf("%d",&b[i]);
        }
        for(int i=1; i<=6; i++){
            scanf("%d",&c[i]);
        }

        for(int i=1; i<=6; i++){
            vis[a[i]]=1;
        }
        for(int i=1; i<=6; i++){
            vis[b[i]]=1;
        }
        for(int i=1; i<=6; i++){
            vis[c[i]]=1;
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (a[i]*10)+b[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (b[i]*10)+a[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (a[i]*10)+c[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (c[i]*10)+a[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (b[i]*10)+c[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                int v = (c[i]*10)+b[j];
                vis[v]=1;
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (a[i]*100) + (b[j]*10) + c[k];
                    vis[v]=1;
                }
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (a[i]*100) + (c[j]*10) + b[k];
                    vis[v]=1;
                }
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (b[i]*100) + (a[j]*10) + c[k];
                    vis[v]=1;
                }
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (b[i]*100) + (c[j]*10) + a[k];
                    vis[v]=1;
                }
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (c[i]*100) + (a[j]*10) + b[k];
                    vis[v]=1;
                }
            }
        }

        for(int i=1; i<=6; i++)
        {
            for(int j=1; j<=6; j++)
            {
                for(int k=1; k<=6; k++)
                {
                    int v = (c[i]*100) + (b[j]*10) + a[k];
                    vis[v]=1;
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=999; i++)
        {
            if(vis[i]==0)
            {
                break;
            }
            ans++;
        }

        printf("%d\n",ans);


    }

    //main();

    return 0;
}
