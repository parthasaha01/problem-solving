#include<bits/stdc++.h>
using namespace std;
set<string>ss;
map<string,int>mp;
map<string,int>sp[25];
vector<string>vv[25];
vector<string>uu[25];
bool cmp(string x,string y)
{
    return x.size()>y.size();
}
int main()
{
    int n; cin>>n;
    int k=0;
    while(n--)
    {
        string name;
        int cnt;
        cin >> name;
        cin >> cnt;
        int id;

        if(mp.find(name)!=mp.end())id=mp[name];
        else{
            ss.insert(name);
            id = ++k;
            mp[name]=k;
        }

        while(cnt--)
        {
            string no;
            cin>>no;
            vv[id].push_back(no);
        }
    }

    for(int i=1; i<=k; i++)
    {
        sort(vv[i].begin(),vv[i].end(),cmp);
    }

    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<vv[i].size(); j++)
        {
            string s = vv[i][j];

            if(sp[i].find(s)!=sp[i].end())continue;

            uu[i].push_back(s);

            string z;
            for(int p=s.size()-1; p>=0; p--)
            {
                z = s[p] + z;
                sp[i][z]=1;
            }
        }
    }

    int res = ss.size();
    cout << res << endl;

    set<string>:: iterator it;

    for(it=ss.begin(); it!=ss.end(); it++)
    {
        int id = mp[*it];
        cout << *it << " " << uu[id].size();
        for(int i=0; i<uu[id].size(); i++){
            cout << " " << uu[id][i];
        }
        cout << endl;
    }

    return 0;
}
