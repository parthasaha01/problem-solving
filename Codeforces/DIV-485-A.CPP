#include<bits/stdc++.h>
using namespace std;
vector<string>vv;
vector<string>uu;
map<string,int>mp;
int main()
{
    int n;cin>>n;

    vv.push_back("purple");
    vv.push_back("green");
    vv.push_back("blue");
    vv.push_back("orange");
    vv.push_back("red");
    vv.push_back("yellow");

    uu.push_back("Power");
    uu.push_back("Time");
    uu.push_back("Space");
    uu.push_back("Soul");
    uu.push_back("Reality");
    uu.push_back("Mind");


    mp.clear();

    for(int i=1; i<=n; i++){
        string s; cin>>s;
        mp[s] = 1;
    }

    int m = 6-n;
    cout << m << endl;
    for(int i=0; i<6; i++){
        if(mp[vv[i]]==0){
            cout << uu[i] << endl;
        }
    }
    //main();
    return 0;
}
