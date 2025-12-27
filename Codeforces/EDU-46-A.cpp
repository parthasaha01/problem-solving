#include<bits/stdc++.h>
using namespace std;
map<string,int>ma;
map<string,int>mb;
string a[105],b[105];
vector<string>v;
int main()
{
    v.push_back("M");
    v.push_back("S");
    v.push_back("XS");
    v.push_back("XXS");
    v.push_back("XXXS");
    v.push_back("L");
    v.push_back("XL");
    v.push_back("XXL");
    v.push_back("XXXL");

    ma.clear(); mb.clear();

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        ma[a[i]]++;
    }
    for(int i=1; i<=n; i++){
        cin>>b[i];
        mb[b[i]]++;
    }

    for(int i=0; i<v.size(); i++){
        if(mb[v[i]]==0)continue;
        if(ma[v[i]]==0)continue;
        if(ma[v[i]]>=mb[v[i]]){
            ma[v[i]] -= mb[v[i]];
            mb[v[i]] = 0;
        }
        else{
            mb[v[i]] -= ma[v[i]];
            ma[v[i]] = 0;
        }
    }

    int ans = 0;

    for(int i=0; i<v.size(); i++){
        ans += mb[v[i]];
    }

    cout << ans << endl;

    return 0;
}
