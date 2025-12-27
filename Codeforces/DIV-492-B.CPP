#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx],b[mx];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    ll n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        ll d = a[i]/n;
        ll dr = (d*n)+i;
        if(a[i]<=dr)b[i] = dr;
        else b[i] = dr+n;
    }

//    for(int i=0; i<n; i++){
//        cout << b[i] << " ";
//    }
//    cout << endl;

    ll ans = 0;
    ll minn = 1000000000000000000;
    for(int i=0; i<n; i++){
        if(b[i]<minn){
            minn = b[i];
            ans = i+1;
        }
    }

    cout << ans << endl;

    //main();

    return 0;
}

