#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
int vis[mx+5],s[1005],a[4005];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d",&s[i]);
        vis[s[i]]=1;
    }

    int flag = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int g = __gcd(s[i],s[j]);
            if(vis[g]==0){
                flag = 1;
                break;
            }
        }

        if(flag==1)break;
    }

    if(flag==1){
        printf("-1\n");
    }
    else{
        printf("%d\n",n);
        for(int i=1; i<=n; i++){
            if(i==n)printf("%d\n",s[i]);
            else printf("%d ",s[i]);
        }
    }

    return 0;
}
