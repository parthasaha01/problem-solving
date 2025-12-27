#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n; scanf("%d",&n);
    int ans = 0;
    for(int i=1; i<=n; i++){
        int x; scanf("%d",&x);
        if(x==0)continue;
        if(a[x]==0)ans++;
        a[x]=1;
    }

    printf("%d\n",ans);

    return 0;
}
