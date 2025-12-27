#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n;
    while(cin>>n){
        if((n%4==0)||(n%4==3)){
            cout<<"0"<<endl;
        }else{
            cout<<"1"<<endl;
        }
    }
    return 0;
}
