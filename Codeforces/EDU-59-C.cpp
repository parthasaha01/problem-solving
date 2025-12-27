#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll>pq[27];
ll a[200005];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=0; i<n; i++)cin>>a[i];
    string s; cin>>s;
    if(n==1){
        ll ans = a[0];
        cout<<ans<<endl;
    }else{
        int id = s[0] - 'a';
        pq[id].push(a[0]);
        int cnt = 1;
        ll ans = 0;
        for(int i=1; i<n; i++){
            int cur = s[i]-'a';
            if(s[i]==s[i-1]){
                pq[cur].push(a[i]);
            }else{
                int prev = s[i-1]-'a';
                int cnt  = 0;
                while(!pq[prev].empty()){
                    if(cnt<k){
                        ll v = pq[prev].top();
                        pq[prev].pop();
                        ans += v;
                        cnt++;
                    }else{
                        pq[prev].pop();
                    }
                }

                pq[cur].push(a[i]);
            }

            if(i==n-1){
                int cnt  = 0;
                while(!pq[cur].empty()){
                    if(cnt<k){
                        ll v = pq[cur].top();
                        pq[cur].pop();
                        ans += v;
                        cnt++;
                    }else{
                        pq[cur].pop();
                    }
                }
            }
        }

        cout<<ans<<endl;
    }

    //main();
    return 0;
}
