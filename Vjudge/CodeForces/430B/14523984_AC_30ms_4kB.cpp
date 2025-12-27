#include<bits/stdc++.h>
using namespace std;
vector<int>a,v,u;
void solve()
{
    int f = 0;
    for(int i=2; i<v.size(); i++){
        if(v[i]==v[i-1]&&v[i]==v[i-2]){
            f = 1;
            int temp = v[i];
            v[i]=v[i-1]=v[i-2]=-1;
            for(int j=i+1; j<v.size(); j++){
                if(v[j]!=temp)break;
                v[j]=-1;
            }
        }
    }

    if(f){
        u = v;
        v.clear();
        for(int i=0; i<u.size(); i++){
            if(u[i]!=-1)v.push_back(u[i]);
        }
        solve();
    }
}
int main()
{
    int n,k,x; cin>>n>>k>>x;
    for(int i=1; i<=n; i++){
        int c; cin>>c;
        a.push_back(c);
    }

    int maxx = 0;

    for(int i=0; i<=n; i++){
        v.clear();
        for(int j=0; j<i; j++){
            v.push_back(a[j]);
        }
        v.push_back(x);
        for(int j=i; j<n; j++){
            v.push_back(a[j]);
        }

        solve();
        int d = v.size();
        int cnt = n-d;
        maxx = max(maxx,cnt);
    }

    if(maxx<2)maxx=0;
    cout << maxx << endl;

    return 0;
}
