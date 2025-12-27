#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int n,a[1005],b[1005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];

    for(int i=1; i<=n; i++){
        if(a[i]&1)b[i]=a[i];
        else b[i]= a[i]-1;
    }

    for(int i=1; i<=n; i++){
        if(i==n)cout<<b[i]<<endl;
        else cout<<b[i]<<" ";
    }

   // main();

    return 0;
}
