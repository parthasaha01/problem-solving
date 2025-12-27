#include<bits/stdc++.h>
using namespace std;
int a[5005];
map<int,int>mp;
int main()
{
    int n; scanf("%d",&n);
    int ans = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
        ans = max(mp[a[i]],ans);
    }

    printf("%d\n",ans);

    return 0;
}
