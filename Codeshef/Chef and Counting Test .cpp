#include<bits/stdc++.h>
using namespace std;
string s,ss;
#define ll long long
int main()
{
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        cin>>s;
        int sz = s.size();

        ll ans = 0;

        if(sz==1){
            printf("%lld\n",ans);
            continue;
        }

        if(sz==2){
            if(s[0]==s[1]) ans++;
            printf("%lld\n",ans);
            continue;
        }

        ss="";
        ll x=1;
        ss += s[0];

        for(int i=1; i<sz; i++)
        {
            if(s[i]==s[i-1]){
                x++;
            }
            else{
                ans += ((x*(x-1))/2);
                ss += s[i];
                x = 1;
            }
        }
        ans += ((x*(x-1))/2);

        int len = ss.size();

        for(int i=0; i<=len-3; i++){
            if(ss[i]==ss[i+2])ans++;
        }

        printf("%lld\n",ans);

    }
    return 0;
}
