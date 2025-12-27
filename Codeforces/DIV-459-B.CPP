#include<bits/stdc++.h>
using namespace std;
//map<string,string<mp;
map<string,string>sp;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        string nam,ip;
        cin>>nam>>ip;
        //mp[nam]=ip;
        sp[ip]=nam;
    }

    for(int i=1; i<=m; i++)
    {
        string nam,ip;
        cin>>nam>>ip;
        string pp;
        for(int j=0; j<(ip.size()-1); j++)
        {
            pp+=ip[j];
        }
        cout << nam << " " << ip << " #" << sp[pp] << endl;
    }

    return 0;
}
