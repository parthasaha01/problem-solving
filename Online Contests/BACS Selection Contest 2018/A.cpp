#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[105];
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int f = 0;
        for(int i=2; i<=n; i++)
        {
            int d = a[i]-a[i-1];
            if(d==1){
                f = 1; break;
            }
        }

        if(f)printf("Case %d: Yes\n",ks);
        else printf("Case %d: No\n",ks);
    }

    return 0;
}
