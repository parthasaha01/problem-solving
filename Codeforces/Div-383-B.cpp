#include<bits/stdc++.h>
using namespace std;
int a[100005],axr[100005];
int main()
{
    int n,x;
    while(cin>>n>>x)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            axr[i] = (a[i]^x );
        }

        map<int,int>mp;

        long long int ans=0;

        for(int i=n; i>=1; i--){
            int v  = a[i];
            int vx = axr[i];
            ans +=(long long int)mp[vx];
            mp[v]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
