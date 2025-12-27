#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int main()
{
    string s;
    while(cin>>s)
    {
        map<string,int>mp;
        int sz = s.size();
        mp[s] = true;
        int cnt = 1;
        while(1)
        {
            int ch = s[sz-1];
            string sp;
            sp += ch;
            s = sp + s;
            string temp = s.substr(0,sz);
            s = temp;
            if(mp[s]==true){
                break;
            }
            cnt++;
            mp[s]=true;
        }

        printf("%d\n",cnt);
    }
    return 0;
}
