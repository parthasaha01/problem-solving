#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int a[205],vs[205];
map<int,int>mp;
vector<int>v[1005],u;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    int n; cin>>n;
    int k = 0;
    for(int i=1; i<=2*n; i++){
        cin>>a[i];
        if(mp[a[i]]==0){
            mp[a[i]] = ++k;
            u.push_back(a[i]);
        }
        v[a[i]].push_back(i);
    }

    int ans = 0;
    memset(vs,0,sizeof(vs));

    for(int i=0; i<u.size(); i++){
        int d = u[i];
        int x = v[d][0];
        int y = v[d][1];
        int cnt = 0;
        for(int j=y-1; j>x; j--){
            if(vs[a[j]]==0)cnt++;
        }
        ans += cnt;
        vs[d] = 1;
    }

    cout << ans << endl;

    mp.clear();
    u.clear();
    for(int i=0; i<=2*n; i++)v[i].clear();

    //main();

    return 0;
}


