#include<bits/stdc++.h>
using namespace std;
string s;
int n,dp[1005],ispalindrome[1005][1005];
int palindrome(int i,int j)
{
    if(i>=j)return ispalindrome[i][j]=1;
//    if(i+1==j){
//        if(s[i]==s[j]) return ispalindrome[i][j]=1;
//        return ispalindrome[i][j]=0;
//    }
    if(ispalindrome[i][j]!=-1)return ispalindrome[i][j];

    int ret = 0;
    if(s[i]==s[j])ret = palindrome(i+1,j-1);

    return ispalindrome[i][j] = ret;
}
int fun(int i)
{
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];

    int ret = 1000000;
    for(int j=i; j<n; j++){
//        printf("i=%d j=%d is=%d\n",i,j,palindrome(i,j));
//        getchar();
        if(palindrome(i,j)==1){
            ret = min(ret,1+fun(j+1));
        }
    }
    return dp[i] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        cin>>s;
        n = s.size();

        memset(ispalindrome,-1,sizeof(ispalindrome));
        //palindrome(0,n-1);

        memset(dp,-1,sizeof(dp));
        int ans = fun(0);
        cout<<"Case "<<ks<<": "<<ans<<endl;
        //cout << ans << endl;
    }
    return 0;
}
