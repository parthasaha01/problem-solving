#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,lm; scanf("%d%d",&n,&lm);

        int sum = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }

        if(sum>lm){
            printf("Case %d: No\n",ks);
            continue;
        }

        bool flag = true;

        for(int i=1; i<=n; i++)
        {
            if(a[i]>b[i]){
                flag = false;
                break;
            }
        }

        if(flag)printf("Case %d: Yes\n",ks);
        else printf("Case %d: No\n",ks);
    }
    return 0;
}
