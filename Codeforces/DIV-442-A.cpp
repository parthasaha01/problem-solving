#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
string s;
int main()
{
    mp["Danil"]=1;
    mp["Olya"]=1;
    mp["Slava"]=1;
    mp["Ann"]=1;
    mp["Nikita"]=1;

    cin>>s;

    int cnt=0;

    for(int i=0; i<s.size(); i++)
    {
        string rr;
        for(int j=i; j<s.size(); j++)
        {
            rr += s[j];
            if(mp[rr]==1)cnt++;
        }
    }

    if(cnt==1)printf("YES\n");
    else printf("NO\n");

    return 0;

}
