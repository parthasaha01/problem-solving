#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
vector<string>vv;
int ispalindrome[1005][1005],ans[1005][1005];
int palindrome(int i,int j)
{
    if((j-i==0)||(j-i==1)){
        if(s[i]==s[j])return 1;
        else return 0;
    }
    if(ispalindrome[i][j]!=-1)return ispalindrome[i][j];
    int ret = 0;
    if(s[i]==s[j])ret = palindrome(i+1,j-1);
    return ispalindrome[i][j] = ret;

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        cin>>n>>q;
        cin>>s;

        memset(ispalindrome,-1,sizeof(ispalindrome));
//        for(int i=0; i<n; i++){
//            for(int j=i; j<n; j++){
//                ans[i][j] = palindrome(i,j);
//            }
//        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(palindrome(i,j)==1){
                    string p;
                    for(int k=i; k<=j; k++){
                        p+=s[k];
                    }
                    vv.push_back(p);
                }
            }
        }

        sort(vv.begin(),vv.end());

//        for(int i=0; i<vv.size(); i++){
//            cout << vv[i] << endl;
//        }

        while(q--)
        {
            int k; char c;
            cin>>k>>c;
            int cnt = 0;
            for(int i=0; i<vv[k-1].size(); i++){
                if(vv[k-1][i]==c)cnt++;
            }
            cout<<cnt<<endl;
        }

        vv.clear();
    }
    return 0;
}
