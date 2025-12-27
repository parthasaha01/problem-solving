#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    //getchar();
    while(t--)
    {
        string s; cin>>s;
        int u=0,p=0,c=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='U')u++;
            if(s[i]=='P')p++;
            if(s[i]=='C')c++;
        }

        c = c/2;

        int ans = min(u,min(p,c));

        cout << ans << endl;

    }
    return 0;
}

