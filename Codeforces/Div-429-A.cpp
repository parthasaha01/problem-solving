#include<bits/stdc++.h>
using namespace std;
int fr[30];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        string s;
        cin>>s;
        memset(fr,0,sizeof(fr));
        int maxx=0;
        for(int i=0; i<s.size(); i++)
        {
            int id = s[i]-'a';
            fr[id]++;
        }
        int mx=0;

        for(int i=0; i<26; i++)
        {
            mx = max(mx,fr[i]);
        }

        if(k<mx)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}
