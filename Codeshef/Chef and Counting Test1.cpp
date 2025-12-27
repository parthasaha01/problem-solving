#include<bits/stdc++.h>
using namespace std;
string s;
#define ll long long
int sz;
int last[27][1000005],now[27];
int main()
{
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        cin>>s;
        sz = s.size();

        ll ans = 0;

        if(sz==1){
            printf("%lld\n",ans);
            continue;
        }

        for(int i=1; i<sz; i++)
        {
            if(s[i]==s[i-1]){
                ans++;
            }
        }

        if(sz==2){
            printf("%lld\n",ans);
            continue;
        }

        for(int i=0; i<26; i++){
            last[i][sz-1]=sz;
            now[i]=sz;
        }

        now[s[sz-1]-'a']=sz-1;

        for(int i=sz-2; i>=0; i--){
            int id = s[i]-'a';
            for(int j=0; j<26; j++){
                last[j][i]=last[j][i+1];
            }
            last[id][i] = now[id];
            now[id]=i;
        }

        for(int i=0; i<=sz-3; i++)
        {
            int id = s[i]-'a';
            int x1 = i;
            int x2 = last[id][i];

            if(x2>=sz || (x2-x1)<=1)continue;

            int d = x2-x1+1;

            if(d==3)
            {
                if(s[x1]!=s[x1+1])ans++;
                continue;
            }

            int flag=0;
            for(int j=0; j<26; j++)
            {
                if(last[j][x1+1]!=last[j][x2-1])flag++;
            }

            if(flag==1)ans++;
        }

        printf("%lld\n",ans);

    }
    return 0;
}

