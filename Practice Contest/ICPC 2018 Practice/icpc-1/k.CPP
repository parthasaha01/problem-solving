#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        //scanf("%d",&n);
        cin>>n;
        vector<string> arr;
        map<string,int>mp;
        mp.clear();
        arr.clear();
        for(int j=1;j<=n;j++)
        {
            string ch;
            cin>>ch;
            mp[ch]++;
        }
        int cnt = 0;
        if(mp["ab"]==0 && mp["ba"]==0)
        {
            if(mp["a"]>0 || mp["aa"]>0) cnt++;
            if(mp["b"]>0 || mp["bb"]>0) cnt++;
            cout << cnt << endl;
        }
        else
        {
            int Min = min(mp["ab"],mp["ba"]);
            int nab = mp["ab"]-Min;
            int nba = mp["ba"]-Min;
            int res;
            if(nab==0 && nba==0)
            {
                res = mp["ab"]*2 + mp["ba"]*2 - (Min*2-1);
            }
            else if(mp["ab"]>0 && mp["ba"]>0)
            {
                res = mp["ab"]*2 + mp["ba"]*2 -1- (Min*2-1);
            }
            else
            {
                res = mp["ab"]*2 + mp["ba"]*2 - Min;
            }
            cout << res << endl;
        }

    }


    return 0;
}
