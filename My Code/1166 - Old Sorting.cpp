#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        bool flag=true;
        int ans=0;
        while(flag)
        {
            flag=false;

            for(int i=1; i<=n; i++){
                if(a[i]!=i){
                    swap(a[i],a[a[i]]);
                    flag=true;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
