#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<int>v[30];
map< int,pair<int,int> >mp;
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);

    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++){
            v[i].push_back(i);
            mp[i] = make_pair(i,0);
        }

        int a,b;
        string s,t;
        while(cin>>s)
        {
            if(s=="quit")break;

            cin>> a >> t >> b;

            if(a==b)continue;
            if(mp[a].first==mp[b].first)continue;

            int ba = mp[a].first;
            int pa = mp[a].second;
            int bb = mp[b].first;
            int pb = mp[b].second;

            if(s=="move"){
                if(t=="onto"){
                    int f = 1;
                    for(int i=v[ba].size()-1; i>pa; i--){
                        int x = v[ba][i];
                        if(x==a||a==b){
                            f = 0; break;
                        }
                    }
                    if(!f)continue;

                    for(int i=v[bb].size()-1; i>pb; i--){
                        int x = v[bb][i];
                        if(x==a||a==b){
                            f = 0; break;
                        }
                    }
                    if(!f)continue;

                    for(int i=v[ba].size()-1; i>pa; i--){
                        int x = v[ba][i];
                        v[ba].pop_back();
                        v[x].push_back(x);
                        mp[x] = make_pair(x,v[x].size()-1);
                    }
                    for(int i=v[bb].size()-1; i>pb; i--){
                        int x = v[bb][i];
                        v[bb].pop_back();
                        v[x].push_back(x);
                        mp[x] = make_pair(x,v[x].size()-1);
                    }

                    v[bb].push_back(a);
                    v[ba].pop_back();
                    mp[a] = make_pair(bb,v[bb].size()-1);
                }
                else{
                    int f = 1;
                    for(int i=v[ba].size()-1; i>pa; i--){
                        int x = v[ba][i];
                        if(x==a||a==b){
                            f = 0; break;
                        }
                    }
                    if(!f)continue;

                    for(int i=v[ba].size()-1; i>pa; i--){
                        int x = v[ba][i];
                        v[ba].pop_back();
                        v[x].push_back(x);
                        mp[x] = make_pair(x,v[x].size()-1);
                    }

                    v[bb].push_back(a);
                    v[ba].pop_back();
                    mp[a] = make_pair(bb,v[bb].size()-1);
                }
            }
            else{
                if(t=="onto"){
                    int f = 1;
                    for(int i=v[bb].size()-1; i>pb; i--){
                        int x = v[bb][i];
                        if(x==a||a==b){
                            f = 0; break;
                        }
                    }
                    if(!f)continue;

                    for(int i=v[bb].size()-1; i>pb; i--){
                        int x = v[bb][i];
                        v[bb].pop_back();
                        v[x].push_back(x);
                        mp[x] = make_pair(x,v[x].size()-1);
                    }

                    for(int i=pa; i<v[ba].size(); i++){
                        int x = v[ba][i];
                        v[bb].push_back(x);
                        mp[x] = make_pair(bb,v[bb].size()-1);
                    }

                    for(int i=v[ba].size()-1; i>=pa; i--) v[ba].pop_back();
                }
                else{
                    for(int i=pa; i<v[ba].size(); i++){
                        int x = v[ba][i];
                        v[bb].push_back(x);
                        mp[x] = make_pair(bb,v[bb].size()-1);
                    }

                    for(int i=v[ba].size()-1; i>=pa; i--) v[ba].pop_back();
                }
            }
        }

        for(int i=0; i<n; i++){
            cout << i <<  ":";
            for(int j=0; j<v[i].size(); j++){
                cout << " " << v[i][j];
            }
            cout << endl;
        }

        mp.clear();
        for(int i=0; i<n; i++)v[i].clear();
    }
    return 0;
}