#include<bits/stdc++.h>
using namespace std;
int d[105];
int main(){
    int w,h,u1,d1,u2,d2;
    cin>>w>>h;
    cin>>u1>>d1;
    cin>>u2>>d2;

    memset(d,0,sizeof(d));

    d[d1] = u1;
    d[d2] = u2;
    int ans = w;
    for(int i=h; i>0; i--){
        ans += i;
        if(d[i]>0) ans -= d[i];
        if(ans<0) ans = 0;
    }

    cout << ans << endl;
    main();
    return 0;
}
