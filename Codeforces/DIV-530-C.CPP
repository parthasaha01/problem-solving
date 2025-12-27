#include<bits/stdc++.h>
using namespace std;
int sz = 0, letter = 0, candy = 0, snow = 0, minlen = 0;
string fun(string s, int n){
    string ans;
    int cur = sz - (snow+candy);
    //cout<<n<<" "<<cur<<endl;
    if(n==cur){
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a'&&s[i]<='z')ans+=s[i];
        }
        return ans;
    }else if(n<cur){
        int rem = cur-n;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a'&&s[i]<='z'){
                if(rem>0){
                    if(i+1<sz && ((s[i+1]=='?') || (s[i+1]=='*'))){
                        rem--;
                    }else{
                        ans += s[i];
                    }
                }else{
                    ans += s[i];
                }
            }
        }
    }else{
        int need = n-cur;
        int flag = 1;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a'&&s[i]<='z'){
                ans += s[i];
            }else if(s[i]=='*'){
                if(flag){
                    for(int j=1; j<=need; j++){
                        ans += s[i-1];
                    }
                    flag = 0;
                }
            }
        }

        return ans;
    }
}
int main(){
    string s; cin>>s;
    int n; cin>>n;
    sz = s.size();
    letter = 0, candy = 0, snow = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='?')candy++;
        else if(s[i]=='*')snow++;
        else letter++;
    }

    minlen = sz - (2*(snow+candy));

    if(n>(sz-candy) && snow==0){
        cout<<"Impossible"<<endl;
    }else if(n!=sz && snow==0 && candy==0){
        cout<<"Impossible"<<endl;
    }else if(n<minlen){
        cout<<"Impossible"<<endl;
    }else{
        string ans = fun(s,n);
        cout<<ans<<endl;
    }

    //main();
    return 0;
}
