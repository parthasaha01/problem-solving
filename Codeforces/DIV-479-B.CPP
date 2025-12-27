#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    int n; cin>>n;
    string s; cin>>s;

    int maxx = 0;
    string ans;
    for(int i=0; i<n-1; i++)
    {
        string tm;
        tm+=s[i];
        tm+=s[i+1];
        int cnt = 0;
        for(int j=0; j<n-1; j++)
        {
            if(s[j]==tm[0]&&s[j+1]==tm[1]){
                cnt++;
            }
        }

        if(cnt>maxx){
            maxx = cnt;
            ans = tm;
        }
    }

    cout << ans << endl;

    //main();

    return 0;
}

