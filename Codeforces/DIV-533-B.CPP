#include<bits/stdc++.h>
using namespace std;
string s;
int n,k;
int main(){
    cin>>n>>k;
    cin>>s;
    int ans = 0;

    for(int c=0; c<26; c++){
        int len = 0, cnt = 0;
        for(int i=0; i<n; i++){
            int ch = s[i]-'a';
            if(ch==c){
                len++;
            }else{
                len = 0;
            }
            if(len==k){
                len = 0;
                cnt++;
            }
        }

        ans = max(ans,cnt);
    }

    cout<<ans<<endl;

    //main();

    return 0;
}
