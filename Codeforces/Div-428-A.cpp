#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }

        int ans=0;
        int sum=0;
        int ace=0;
        bool flag = false;
        for(int i=1; i<=n; i++)
        {
            ace += a[i];
            ans++;
            int v = min(8,ace);
            sum += v;
            ace -= v;
            if(sum>=k){
                flag = true;
                break;
            }
        }

        if(flag==true){
            printf("%d\n",ans);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}
