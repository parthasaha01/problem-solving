#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    string s;
    cin>>s;

    string ans;
    int v=0;
    char ch;
    int sz = s.size();
    for(int i=0; i<n; i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y')
        {
            if(v==0)
            {
                ans += s[i];
                v=1;
            }
        }
        else
        {
            v = 0;
            ans += s[i];
        }
    }

    //reverse(ans.begin(),ans.end());

    cout << ans << endl;

   // main();

    return 0;
}
