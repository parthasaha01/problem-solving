#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n;
vector<ll>a,b;
bool cmp(ll x,ll y){
    return x>y;
}
ll fun()
{
    ll ans=0,res=0;
    int x=0,y=0;
    int k=0;
    while(x<n||y<n)
    {
        if(k==0)
        {
            if(x>=n){
                if(y<n)y++;
            }
            else if(y>=n){
                ans += a[x];
                x++;
            }
            else{
                if(a[x]>=b[y]){
                    ans += a[x];
                    x++;
                }
                else{
                    y++;
                }
            }
        }
        else
        {
            if(y>=n){
                if(x<n)x++;
            }
            else if(x>=n){
                res += b[y];
                y++;
            }
            else{
                if(b[y]>=a[x]){
                    res += b[y];
                    y++;
                }
                else{
                    x++;
                }
            }
        }

        k = 1-k;
    }

    ll ret = ans - res;

    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

    a.clear();
    b.clear();

    for(int i=0; i<n; i++){
        ll x; cin>>x;
        a.push_back(x);
    }
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        b.push_back(x);
    }

    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);

    ll ans = fun();

    cout << ans << endl;

    //main();
    return 0;
}

