#include<bits/stdc++.h>
using namespace std;

int solve(int n, string s){
    int open = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            open++;
        }else{
            if(open==0){
                ans++;
            }else{
                open--;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tt; cin>>tt;
    for(int t=1; t<=tt; t++){
        int n; cin>>n;
        string s; cin>>s;
        cout<<solve(n, s)<<endl;
    }
    return 0;
}



