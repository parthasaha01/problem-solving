#include<bits/stdc++.h>
using namespace std;
string s;
int fun(){
    int n = s.size();
    stack<char>st;
    int cnt = 0;
    st.push(s[0]);
    for(int i=1; i<n; i++){
        char c = s[i];
        if(st.empty()){
            st.push(c);
        }else{
            char top = st.top();
            if(c==top){
                st.pop();
                cnt++;
            }else{
                st.push(c);
            }
        }
    }

    if(cnt&1) return 1;
    else return 0;
}
int main(){
    cin>>s;

    int f = fun();

    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

   // main();

    return 0;
}
