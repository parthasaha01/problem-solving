#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
int cnt[100];
int main()
{
    while(cin>>s)
    {
        int sz=s.size();

        if(sz<26)
        {
            printf("-1\n");
            continue;
        }
        memset(cnt,0,sizeof(cnt));
        int ques=0,need=26;

        for(int i=0; i<26; i++)
        {
            if(s[i]=='?')
            {
                ques++;
            }
            else
            {
                int c=s[i]-'A'+1;
                if(cnt[c]==0)
                {
                    need--;
                }
                cnt[c]++;
            }
        }

        v.clear();

        for(int i=1; i<=26; i++)
        {
            if(cnt[i]==0)
            {
                v.push_back(i);
            }
        }

        if(need==ques)
        {
            //char ss[100];
            for(int i=0,k=0; i<26; i++)
            {
                if(s[i]=='?')
                {
                    s[i]=v[k]+'A'-1;
                    k++;
                }
            }
            for(int i=26; i<sz; i++){
                if(s[i]=='?'){
                    s[i]='A';
                }
            }
            cout << s << endl;
            continue;
        }

        bool flag=true;

        for(int i=26; i<sz && flag; i++)
        {
            char pr=s[i-26];

            if(pr=='?')
            {
                ques--;
            }
            else
            {
                int c=pr-'A'+1;
                cnt[c]--;
                if(cnt[c]==0)
                {
                    need++;
                }
            }

            if(s[i]=='?')
            {
                ques++;
            }
            else
            {
                int c=s[i]-'A'+1;
                if(cnt[c]==0)
                {
                    need--;
                }
                cnt[c]++;
            }

            v.clear();

            for(int j=1; j<=26; j++)
            {
                if(cnt[j]==0)
                {
                    v.push_back(j);
                }
            }

            if(need==ques)
            {
                for(int j=i-26+1,k=0; j<=i; j++)
                {
                    if(s[j]=='?')
                    {
                        s[j]=v[k]+'A'-1;
                        k++;
                    }
                }

                flag=false;
            }

        }

        if(flag){
            printf("-1\n");
        }
        else{
            for(int i=0; i<sz; i++){
                if(s[i]=='?'){
                    s[i]='A';
                }
            }

            cout << s << endl;
        }

    }

    return 0;
}
/*

ABCDEFGHIJKLMNOPQRSTUVWXY?
ABCDEFGHIJKLMNOPQRSTUVWXZ?
ABCDEFGHIJKLMNOPQRSTUA????
ABCDEFGHIJKLMNOPQRSTUA????ZYVW
WELCOMETOCODEFORCESROUNDTHREEHUNDREDANDSEVENTYTWOABCDEFGHIJKLMNOPQRSTUA????ZYVWABCDEFGHIJKLMNOPQRSTUVWXY?
*/
