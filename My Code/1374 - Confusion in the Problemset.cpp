#include<bits/stdc++.h>
using namespace std;
int a[10005],cnt[10005],vis[10005];

int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        sort(a,a+n);
        memset(cnt,0,sizeof(cnt));

        bool flag=true;
        for(int i=0; i<n; i++){
            if(a[i]>=n){
                flag=false;
                break;
            }
            cnt[a[i]]++;
            if(cnt[a[i]]>2)
            {
                flag=false;
                break;
            }

        }

        if(!flag){
            printf("Case %d: no\n",ks);
            continue;
        }

        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<n; i++){
            cnt[a[i]]++;
            if(cnt[a[i]]==2){
                vis[a[i]]=2;
                vis[n-a[i]-1]=2;
            }
        }

        flag=true;
        for(int i=0; i<n; i++){
            if(cnt[a[i]]==1){
                if(vis[a[i]]==2&&vis[n-a[i]-1]==2){
                    flag=false;
                    break;
                }
                else{
                    if(vis[a[i]]==2){
                        vis[n-a[i]-1]=2;
                    }
                    else if(vis[n-a[i]-1]==2){
                        vis[a[i]]=2;
                    }
                    else{
                        if(vis[a[i]]==0){
                            vis[a[i]]=2;
                        }
                        else if(vis[n-a[i]-1]==0){
                            vis[n-a[i]-1]=2;
                        }

                    }
                }
            }
        }

        if(flag){
            printf("Case %d: yes\n",ks);
        }
        else{
            printf("Case %d: no\n",ks);
        }
    }

    return 0;
}
