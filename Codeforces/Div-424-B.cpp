#include<bits/stdc++.h>
using namespace std;
string a,b,p,s;
map<char,char>mp;
int main()
{
    cin>>a;
    cin>>b;
    cin>>p;

    for(int i=0; i<26; i++)
    {
        mp[a[i]]=b[i];
    }

    for(int i=0; i<p.size(); i++)
    {
        if(p[i]>='0' && p[i]<='9')
        {
            s+=p[i];
        }
        else if(p[i]>='A'&&p[i]<='Z')
        {
            char ch = p[i];
            ch += 32;

            ch = mp[ch];
            ch -= 32;
            s += ch;
        }
        else
        {
            char ch = p[i];
            ch = mp[ch];
            s += ch;
        }
    }

    cout << s << endl;

    return 0;
}
