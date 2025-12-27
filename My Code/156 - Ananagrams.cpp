#include<bits/stdc++.h>
using namespace std;
vector<string>v,ans;
map<string,int>mp;
map<string,string>vp;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin>>s){
        if(s=="#")break;
        v.push_back(s);
    }

    int n = v.size();

    for(int i=0; i<n; i++)
    {
        string x = v[i];
        for(int j=0; j<x.size(); j++){
            if(x[j]>='A'&&x[j]<='Z')x[j]+=32;
        }
        sort(x.begin(),x.end());
        mp[x]++;
        vp[v[i]] = x;
    }

    for(int i=0; i<n; i++){
        if(mp[vp[v[i]]]==1)
            ans.push_back(v[i]);
    }

    sort(ans.begin(),ans.end());

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}
