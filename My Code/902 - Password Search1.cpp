#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;

    while(cin >> n >> s)
    {
        int sz=s.size();
        map<string,int>mp;

        for(int i=0; i<=sz-n; i++)
        {
            string s1 = s.substr(i,n);
            mp[s1]++;
        }

        int maxx=0;
        string res;

        for(map<string,int>::iterator it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second>maxx){
                maxx=it->second;
                res=it->first;
            }
        }

        cout << res << endl;
    }

    return 0;
}

