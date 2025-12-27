#include<bits/stdc++.h>
using namespace std;

int fun(string s) {
    int cnto = 0, cntc = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(')cnto++;
        else cntc++;
    }
    if(cnto != cntc)return -1;
    int ans = 0;
    int cnt = 0;
    stack<char>open;
    stack<char>close;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') {
            if((int)close.size() == 0){
                open.push('(');
            }else{
               close.pop();
               cnt++;
               if((int)close.size() == 0){
                    ans += cnt;
                    cnt = 0;
               }
            }
        }else{
            if((int)open.size() == 0){
                close.push(')');
                cnt++;
            }else{
                open.pop();
            }
        }
    }

    if(cnt != 0) return -1;
    if((int)open.size() > 0) return -1;
    if((int)close.size() > 0) return -1;

    return ans;
}
int main() {
    int n; cin>> n;
    string s; cin>>s;
    int ans = fun(s);
    cout<<ans<<endl;
    return 0;
}
