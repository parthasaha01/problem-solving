#include<bits/stdc++.h>
using namespace std;
int a[200005];
map<int, int>mp;
int main() {
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++) {
        int n,k,d; scanf("%d%d%d",&n,&k,&d);
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        int ans = 10000000;
        mp.clear();
        for(int i=1; i<=d; i++){
            mp[a[i]]++;
        }
        ans = min(ans, (int)mp.size());
        for(int i=d+1, j=1; i<=n; i++, j++){
            mp[a[j]]--;
            if(mp[a[j]]==0){
                mp.erase(a[j]);
            }

            mp[a[i]]++;
            ans = min(ans, (int)mp.size());
        }

        printf("%d\n",ans);
    }

    return 0;
}
