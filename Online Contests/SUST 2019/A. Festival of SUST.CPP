#include<bits/stdc++.h>
using namespace std;
map<string, int>mp;
string s;
vector<string>v;
int solve(){
    mp.clear();

    for(int i=0; i<s.size(); i++){
        if(!(s[i]>='A' && s[i]<='Z')){
            s[i] = ' ';
        }
    }

    s += ' ';

    v.clear();
    string word;
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]==' '){
            if((int)word.size()==3){
                if(mp.find(word) == mp.end()){
                    mp[word] = 1;
                    cnt++;
                }
            }
            word="";
        }else{
            word += s[i];
        }
    }

    if(cnt==1 && mp["CSE"]==1) return 1;
    else if(cnt>=3 && mp["CSE"]==1 && mp["EEE"]==1 && mp["SWE"]==1) return 2;
    return 3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt; cin>>tt;
    cin.ignore();
    for(int ks=1; ks<=tt; ks++) {

        getline(cin,s);
        //cout<<s<<endl;

        int ans = solve();

        if(ans==1) {
            cout<<"Case "<<ks<<": "<<"SUST CSE Carnival"<<endl;
        }else if(ans==2){
            cout<<"Case "<<ks<<": "<<"SUST Tech Fest"<<endl;
        }else{
            cout<<"Case "<<ks<<": "<<"Festival of SUST"<<endl;
        }
    }

    return 0;
}

