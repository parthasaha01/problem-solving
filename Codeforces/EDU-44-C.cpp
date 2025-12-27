#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll a[mx],b[mx];
ll n,k,l,m;
int vis[mx];
ll binary_Search(int lo,int hi,ll v)
{
    int p = -1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        if(a[md]<=v){
            p = md;
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return p;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k>>l;
    m = n*k;
    for(int i=0; i<m; i++){
        cin>>a[i];
    }

    sort(a,a+m);

    if(n==1){
        cout << a[0] << endl;
        return 0;
    }

    ll val = abs(l+a[0]);
    vis[0] = 1;
    b[0] = a[0];
    int lo = 1, hi = m-1;
    int p = binary_Search(lo,hi,val);
//    if(p==-1)
//    {
//        cout << "0" << endl;
//        return 0;
//    }

    if((p+1)<n){
        cout << "0" << endl;
        return 0;
    }

    for(int i=n-1; i>0; i--)
    {
        b[i] = a[p];
        vis[p] = 1;
        p--;
    }

    sort(b,b+n);

    if(k==1)
    {
        ll ans = 0;
        for(int i=0; i<n; i++){
            ans += b[i];
        }
        cout << ans << endl;
        return 0;
    }

    int cur = 0;
    int fr = 1;
    for(int i=0; i<m; i++){
        if(vis[i]==1)continue;
        vis[i] = 1;
        b[cur] = min(b[cur],a[i]);
        fr++;
        if(fr==k){
            fr = 1;
            cur++;
        }
    }

    //cout << cur << " " << fr << endl;

//    if(cur!=n){
//        while(1)
//        {
//            //
//        }
//    }

//    if(abs(b[0]-b[n-1])>l){
//        cout << "0" << endl;
//        return 0;
//    }

    ll ret = 0;
    for(int i=0; i<n; i++){
        ret += b[i];
    }

    cout << ret << endl;

    return 0;
}
