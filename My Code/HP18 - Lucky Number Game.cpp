#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n,a,b; cin>>n>>a>>b;
        int bob,alice,both;
        bob = alice = both = 0;
        for(int i=1; i<=n; i++){
            int x; cin>>x;
            if(x%a==0 && x%b==0) both++;
            else if(x%a==0) bob++;
            else if(x%b==0) alice++;
        }

        if(bob==0 && alice==0 && both==0){
            cout << "ALICE" << endl;
        }else if(bob>alice){
            cout << "BOB" << endl;
        }else if(bob<alice){
            cout << "ALICE" << endl;
        }else{
            if(both==0){
                cout << "ALICE" << endl;
            }else{
                cout << "BOB" << endl;
            }
        }
    }
    return 0;
}
