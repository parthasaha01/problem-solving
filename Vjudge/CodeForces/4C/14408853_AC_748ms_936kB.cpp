#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;

    for(int i=1; i<=n; i++)
    {
        string s; cin>>s;
        if(mp.find(s)==mp.end()){
            cout << "OK" << endl;
            mp[s]++;
        }
        else{
            cout << s << mp[s] << endl;
            mp[s]++;
        }
    }

    return 0;
}
