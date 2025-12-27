#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    cin.ignore();
    while(tt--){
        string s; getline(cin,s);
        bool flag = false;
        string word;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(word=="not"){
                    flag = true;
                    break;
                }else{
                    word="";
                }
            }else{
                word += s[i];
            }
        }

        if((int)word.size()>0 && word=="not"){
            flag = true;
        }

        if(flag){
            cout << "Real Fancy" << endl;
        }else{
            cout << "regularly fancy" << endl;
        }
    }
    return 0;
}
