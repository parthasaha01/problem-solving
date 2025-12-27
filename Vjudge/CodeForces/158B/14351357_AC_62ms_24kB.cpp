#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    int n; scanf("%d",&n);

    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        a[x]++;
    }

    int ans = 0;
    ans += a[4];
    ans += a[3];
    a[1] = max(0,a[1]-a[3]);
    if(a[2]>0){
        if(a[2]%2==0){
            ans += a[2]/2;
        }
        else{
            ans += a[2]/2;
            ans++;
            a[1] = max(0,a[1]-2);
        }
    }

    if(a[1]>0){
        if(a[1]%4==0){
            ans += a[1]/4;
        }
        else{
            ans += a[1]/4;
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}
