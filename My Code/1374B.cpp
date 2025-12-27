#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, int>
map<ll,int>mp;

int solve(ll n){
    if(n==1) return 0;

    mp.clear();

    mp[n] = 1;
    queue< pair<ll, int> >q;
    q.push(make_pair(n, 0));
    int k = 1;
    while(!q.empty()){
        pii p = q.front();
        q.pop();

        int x = p.first;
        int c = p.second;

        ll y = 2*x;
        if(y==1) return c+1;
        if(y <= 10000000000000000LL && mp[y] == 0){
            q.push(make_pair(y, c+1));
            mp[y] = 1;
        }


        if(x%6 == 0){
            ll z = x/6;
            if(z==1) return c+1;
            if(mp[z] == 0) {
                q.push(make_pair(z, c+1));
                mp[z] = 1;
            }

        }

        k++;
        if(k>5000)break;
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int t=1; t<=tt; t++){
        ll n; cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}


