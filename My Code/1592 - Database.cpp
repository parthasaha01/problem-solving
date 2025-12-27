#include<bits/stdc++.h>
using namespace std;
#define UNIQUE(v) (v).erase(unique((v).begin(),(v).end()),(v).end())
vector<string>vv[10005];
map<string, vector<int> > mp[15];
int n,m;
int check(int p,int q,int j)
{
    for(int i=0; i<m; i++)
    {
        if(i==j)continue;
        if(vv[p][i]==vv[q][i])return i;
    }
    return -1;
}
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);

    while(cin>>n>>m)
    {
        cin.ignore();
        for(int i=1; i<=n; i++)
        {
            string s;
            getline(cin,s);

            string t;
            for(int j=0; j<s.size(); j++){
                if(s[j]==','){
                    vv[i].push_back(t);
                    t="";
                }
                else{
                    t += s[j];
                }
            }
            if(t!="")vv[i].push_back(t);
        }

        for(int j=0; j<m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                mp[j][vv[i][j]].push_back(i);
            }
        }

        for(int j=0; j<m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                UNIQUE(mp[j][vv[i][j]]);
            }
        }

        int flag = 0;
        int r1,r2,c1,c2;
        for(int j=0; j<m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(mp[j][vv[i][j]].size()>=2)
                {
                    int sz= mp[j][vv[i][j]].size();
                    for(int x=0; x<sz; x++)
                    {
                        for(int y=x+1; y<sz; y++)
                        {
                            int p = mp[j][vv[i][j]][x];
                            int q = mp[j][vv[i][j]][y];
                            int f = check(p,q,j);
                            if(f!=-1){
                                flag = 1;
                                r1 = min(p,q);
                                r2 = max(p,q);
                                c1 = min(j+1,f+1);
                                c2 = max(j+1,f+1);
                                break;
                            }
                        }
                        if(flag)break;
                    }
                     if(flag)break;
                }
                 if(flag)break;
            }
             if(flag)break;
        }

        if(flag){
            cout << "NO" << endl;
            cout << r1 << " " << r2 << endl;
            cout << c1 << " " << c2 << endl;
        }
        else{
            cout << "YES" << endl;
        }

        for(int i=0; i<=n; i++)vv[i].clear();
        for(int i=0; i<=m; i++)mp[i].clear();
    }
    return 0;
}
