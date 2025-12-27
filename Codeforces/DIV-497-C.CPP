#include<bits/stdc++.h>
using namespace std;
#define lll long long
#define mx 100005
int n,a[mx],b[mx];
multiset<int>ss;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ss.insert(a[i]);
        mp[a[i]]++;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        int v = a[i];
        auto it = ss.upper_bound(v);
        int p = *it;
        //cout << i <<  " " << v << " " << p << endl;
        if(p<=v || mp[p]==0){
            it = ss.begin();
            p = *it;
            b[i] = p;
            mp[p]--;
            if(mp[p]==0) ss.erase(p);
        }
        else{
            ans++;
            b[i]=p;
            mp[p]--;
            if(mp[p]==0) ss.erase(p);
        }
    }

    //for(int i=0; i<n; i++)cout<<b[i]<<" ";
    //cout<<endl;

    cout << ans << endl;

    //main();

    return 0;
}
