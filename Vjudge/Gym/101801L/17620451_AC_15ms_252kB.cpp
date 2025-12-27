#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int odd,even;
        if(n%2==0){
            odd = n/2;
            even = n/2;
        }else{
            odd = (n/2)+1;
            even = n/2;
        }
        cout<<odd<<" "<<even<<endl;
    }
    return 0;
}

