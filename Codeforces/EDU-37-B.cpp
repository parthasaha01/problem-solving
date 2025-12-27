#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int a[1005];
int lf[1005],rg[1005];
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++){
            scanf("%d%d",&lf[i],&rg[i]);
        }

        int cur = 1;
        for(int i=1; i<=n; i++)
        {
            cur = max(cur,lf[i]);

            if(rg[i]<cur){
                a[i]=0;
            }
            else{
                a[i] = cur;
                cur++;
            }
        }

        for(int i=1; i<=n; i++){
            if(i<n)printf("%d ",a[i]);
            else printf("%d\n",a[i]);
        }

    }

    return 0;
}

