#include<bits/stdc++.h>
using namespace std;
string fun(string t) {
    int zero=0, one=0;
    string s;
    for(int i=0; i<t.size(); i++) {
        if(t[i]=='0') zero++;
        else one++;
        s += "01";
    }
    if(zero==0 || one==0){
        return t;
    }else{
       return s;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--) {
        string t; cin>>t;
        cout<<fun(t)<<endl;
    }
    return 0;
}

