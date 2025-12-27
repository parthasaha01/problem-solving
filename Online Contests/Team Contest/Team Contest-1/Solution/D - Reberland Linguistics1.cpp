#include<bits/stdc++.h>
using namespace std;
int dp[100000][4];
int main()
{
    string s;
    while(cin>>s)
    {

        int n=s.length();
        dp[n][2]=dp[n][3]=1;
        set<string > ans;
        ans.clear();
        for(int i=n-2; i>=5; i--)
        {
            if(dp[i+2][3]||(dp[i+2][2]&&s.substr(i,2)!=s.substr(i+2,2)))
            {
                dp[i][2]=1;
                ans.insert(s.substr(i,2));
            }

            if(dp[i+3][2]||(dp[i+3][3]&&s.substr(i,3)!=s.substr(i+3,3)))
            {
                dp[i][3]=1;
                ans.insert(s.substr(i,3));

            }
        }
        cout<<(int)ans.size()<<endl;
        set<string>::iterator it;

        for(it=ans.begin(); it!=ans.end(); it++)
        {
            cout << (*it) << endl;
        }

    }

    return 0;
}
