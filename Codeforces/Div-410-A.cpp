#include<bits/stdc++.h>
using namespace std;
string ss,tt,rr;
int fun()
{

    for(int i=0; i<ss.size(); i++)
    {
        tt = ss;
        for(int k=0; k<26; k++)
        {
            char ch = 'a'+k;
            if(ss[i]==ch)continue;

            tt[i] = ch;
            rr = tt;
            reverse(rr.begin(),rr.end());

            if(tt==rr)return true;
        }
    }

    return false;
}
int main()
{

    while(cin>>ss)
    {
        int ans = fun();

        if(ans)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
