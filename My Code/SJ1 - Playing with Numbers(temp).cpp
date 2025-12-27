#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dt{
    int i,j,k;
};
vector<dt>vv;
ll a[100005];
ll b[100005];
ll n,m;
ll solve(ll x,ll y,ll z){
    return (x+y+z)%m;
}
int main() {
    cout<<"Enter number of Element of the array: ";
    cin>>n;
    cout<<"Enter all elements: "<<endl;
    ll gcd = 0;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        gcd = __gcd(a[i],gcd);
    }

    cout<<endl;

    cout<<"Enter mod value: ";
    cin>>m;

    ll maxx = 1;
    vv.clear();
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            for(int k=0; k<=100; k++) {
                ll x = a[1]*i;
                ll y = a[2]*j;
                ll z = a[3]*k;

                ll val = solve(x,y,z);

                if(val>=maxx) {
                    if(val==maxx){
                        vv.push_back({i,j,k});
                    }else{
                        vv.clear();
                        vv.push_back({i,j,k});
                    }
                    maxx = val;
                }
            }
        }
    }

    cout<<"GCD = "<<gcd<<endl;
    cout<<"Maximum Value: "<<maxx<<endl;
    cout<<"Count: "<<vv.size()<<endl;
//    for(int i=0; i<vv.size(); i++) {
//        cout<<vv[i].i<<" "<<vv[i].j<<" "<<vv[i].k<<", ";
//        cout<<vv[i].i*a[1]<<" "<<vv[i].j*a[2]<<" "<<vv[i].k*a[3]<<endl;
//    }

    cout<<endl<<endl;

    main();
}
