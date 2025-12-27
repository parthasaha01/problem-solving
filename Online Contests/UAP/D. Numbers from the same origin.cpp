#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        string xx, yy;
        cin>> xx >> yy;

        int sx = xx.size();
        int sy = yy.size();

        mp.clear();

        for(int i=2; i<sy; i++)
        {
            string s;
            s+=yy[i-2];
            s+=yy[i-1];
            s+=yy[i];
            mp[s]=1;
        }

        bool f = false;

        for(int i=2; i<sx; i++)
        {
            string s;
            s+=xx[i-2];
            s+=xx[i-1];
            s+=xx[i];

            if(mp[s]==1){
                f = true;
                break;
            }
        }

        if(f)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

