#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vv;
int main()
{
    ll l,r,x,y;
    cin>>l>>r>>x>>y;

    vv.clear();
    for(ll d=1; d*d<=y; d++){
        if(y%d==0){
            vv.push_back(d);
            if(d!=(y/d))vv.push_back(y/d);
        }
    }

    sort(vv.begin(),vv.end());

    ll ans = 0;
    for(int i=0; i<vv.size(); i++){
        for(int j=0; j<vv.size(); j++){
            if(vv[i]>=l&&vv[i]<=r&&vv[j]>=l&&vv[j]<=r){
                ll gcd = __gcd(vv[i],vv[j]);
                ll lcm = (vv[i]*vv[j])/gcd;
                if(gcd==x&&lcm==y)ans++;
            }
        }
    }

    cout << ans << endl;

    //main();

    return 0;
}
