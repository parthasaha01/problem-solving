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

        //sort(a,a+n);
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        bool flag=true;
        for(int i=0; i<n; i++){
            if(a[i]>=n){
                flag=false;
                break;
            }
            cnt[a[i]]++;
            if(cnt[a[i]]==2){
                vis[a[i]]=true;
                vis[n-a[i]-1]=true;
            }
            else if(cnt[a[i]]>2){
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("Case %d: no\n",ks);
            continue;
        }

        flag=true;
        for(int i=0; i<n; i++){
            if(cnt[a[i]]==1){
                if(vis[a[i]]&&vis[n-a[i]-1]){
                    flag=false;
                    break;
                }
                else{
                    if(vis[a[i]]){
                        vis[n-a[i]-1]=true;
                    }
                    else if(vis[n-a[i]-1]){
                        vis[a[i]]=true;
                    }
                    else{
                        if(!vis[a[i]]){
                            vis[a[i]]=true;
                        }
                        else if(!vis[n-a[i]-1]){
                            vis[n-a[i]-1]=true;
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
