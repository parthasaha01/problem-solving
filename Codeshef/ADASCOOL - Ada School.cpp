#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt; cin>>tt;
    while(tt--){
        int n,m; cin>>n>>m;
        int nm = n*m;
        if(nm%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
