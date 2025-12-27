#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    for(int ks=1; ks<=t; ks++)
    {
        map<string, int>mp;
        string ans,s;
        int k;
        cin >> k;
        int maxx=0;
        for(int i=0; i<k; i++)
        {
            cin >> s;
            mp[s]++;

            if(mp[s]>=maxx){
                maxx=mp[s];
                ans=s;
            }

        }

        cout << "Case " << ks <<": " << ans << endl;
        mp.clear();
    }

    return 0;
}
