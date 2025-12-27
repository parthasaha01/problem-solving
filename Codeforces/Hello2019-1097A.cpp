#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 100005
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    map<char,int>mp;
    mp[s[0]] = 1;
    mp[s[1]] = 1;
    int flag = 0;
    for(int i=1; i<=5; i++){
        string x; cin>>x;
        if(mp[x[0]]==1)flag = 1;
        if(mp[x[1]]==1)flag = 1;
    }

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    //main();

    return 0;
}
