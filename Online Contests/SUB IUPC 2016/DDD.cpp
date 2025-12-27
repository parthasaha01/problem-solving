#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    string ss;
    int mx = 0;
    string ans;
    while(cin>>ss)
    {
        mp[ss]++;
        if(mp[ss]>mx){
            mx = mp[ss];
            ans = ss;
        }
    }

    cout << ans << endl;

    return 0;
}
