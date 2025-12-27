#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);
        int ans = 0,k = 0;
        map<int,int>last;
        int cur = 1;
        for(int i=1; i<=n; i++)
        {
            int v; scanf("%d",&v);
            if(last[v]<cur){
                ++k;
                ans = max(ans,k);
                last[v] = i;
            }
            else{
                cur = last[v]+1;
                k = i-last[v];
                ans = max(ans,k);
                last[v] = i;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
