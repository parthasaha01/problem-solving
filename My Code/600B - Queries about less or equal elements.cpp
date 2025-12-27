#include<bits/stdc++.h>
using namespace std;
vector<int>a,b,c;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0; i<n; i++){
        int x; cin>>x; a.push_back(x);
    }
    for(int i=0; i<m; i++){
        int x; cin>>x; b.push_back(x);
    }

    a.push_back(1000000005);
    sort(a.begin(),a.end());

    for(int i=0; i<m; i++){
        int cnt = upper_bound(a.begin(),a.end(),b[i])-a.begin();
        c.push_back(cnt);
    }

    for(int i=0; i<m; i++){
        if(i==m-1)cout<<c[i]<<endl;
        else cout<<c[i]<<" ";
    }

    return 0;
}
