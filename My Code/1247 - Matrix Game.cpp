#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[55];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        memset(a,0,sizeof(a));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x;
                scanf("%d",&x);
                a[i]+=x;
            }
        }

        ll ans=0;
        for(int i=0; i<m; i++)
        {
            ans^=a[i];
        }

        if(ans>0)
            printf("Case %d: Alice\n",ks);
        else
            printf("Case %d: Bob\n",ks);
    }

    return 0;
}
