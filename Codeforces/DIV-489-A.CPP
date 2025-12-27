#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int>mp;
int a[100005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        mp.clear();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(a[i]!=0){
                if(mp.find(a[i])==mp.end()){
                    ans++;
                }
                mp[a[i]]=1;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
