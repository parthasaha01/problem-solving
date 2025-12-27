#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>mp;
    string s;
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        if(mp[s]==1)printf("YES\n");
        else printf("NO\n");

        mp[s]=1;
    }

    return 0;
}
