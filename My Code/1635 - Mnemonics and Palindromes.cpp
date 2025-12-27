#include<bits/stdc++.h>
using namespace std;
string s;
int n,dp[4005],ispalindrome[4005][4005];
vector< pair<int,int> >vv;
int palindrome(int i,int j){
    if(i>=j)return ispalindrome[i][j]=1;
    if(ispalindrome[i][j]!=-1)return ispalindrome[i][j];
    int ret = 0;
    if(s[i]==s[j])ret = palindrome(i+1,j-1);
    return ispalindrome[i][j] = ret;
}
int fun(int i){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int ret = 1000000;
    for(int j=i; j<n; j++){
        if(palindrome(i,j)==1){
            ret = min(ret,1+fun(j+1));
        }
    }
    return dp[i] = ret;
}
void path(int i){
    if(i==n)return;
    int ret = fun(i);
    for(int j=i; j<n; j++){
        if(palindrome(i,j)==1){
            int cnt = 1 + fun(j+1);
            if(cnt==ret){
                vv.push_back(make_pair(i,j));
                path(j+1);
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s; n = s.size();
    memset(ispalindrome,-1,sizeof(ispalindrome));
    memset(dp,-1,sizeof(dp));
    int ans = fun(0);
    cout<<ans<<endl;
    path(0);
    for(int i=0; i<vv.size(); i++){
        int Start = vv[i].first;
        int End = vv[i].second;
        for(int j=Start; j<=End; j++){
            cout << s[j];
        }
        if(i==(int)vv.size()-1)cout << endl;
        else cout << " ";
    }

    return 0;
}


