#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        string s; cin>>s;
        //int n = s.size();
        if(n==2){
            if(s[0]>=s[1]){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
                cout<<"2"<<endl;
                cout<<s[0]<<" "<<s[1]<<endl;
            }
        }else{
            cout<<"YES"<<endl;
            cout<<"2"<<endl;
            string s1, s2;
            s1 += s[0];
            for(int i=1; i<n; i++)s2+=s[i];
            cout<<s1<<" "<<s2<<endl;
        }
    }

    return 0;
}

