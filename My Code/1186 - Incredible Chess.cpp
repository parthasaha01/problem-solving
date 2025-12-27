#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],w[105];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d",&w[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d",&b[i]);
        }
        for(int i=0; i<n; i++){
            a[i]=b[i]-w[i]-1;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans^=a[i];
        }
        if(ans>0)
            printf("Case %d: white wins\n",ks);
        else
            printf("Case %d: black wins\n",ks);
    }

    return 0;
}
