#include<bits/stdc++.h>
using namespace std;
#define mxx 100005
int a[mxx+5];
int main()
{
    int n;
    scanf("%d",&n);
    int mx=0;
    int mn=1000000005;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        mn = min(a[i],mn);
        mx = max(a[i],mx);
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        if(a[i]>mn && a[i]<mx){
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}
