#include<bits/stdc++.h>
using namespace std;
int ss[15],mm[15];
int main()
{
    int n;
    while(cin>>n)
    {
        string s,m;
        cin>>s>>m;

        memset(ss,0,sizeof(ss));
        memset(mm,0,sizeof(mm));

        for(int i=0; i<s.size(); i++){
            int v = s[i]-'0';
            ss[v]++;
        }

        for(int i=0; i<m.size(); i++){
            int v = m[i]-'0';
            mm[v]++;
        }

        int minn = 0;

        for(int i=9; i>=0; i--)
        {
            int cs = ss[i];

            if(cs==0)continue;

            for(int j=i; j<=9 && cs>0; j++){
                if(cs<=mm[j]){
                    mm[j]-=cs;
                    cs=0;
                }
                else{
                    cs-=mm[j];
                    mm[j]=0;
                }
            }

            minn += cs;
        }

        memset(ss,0,sizeof(ss));
        memset(mm,0,sizeof(mm));

        for(int i=0; i<s.size(); i++){
            int v = s[i]-'0';
            ss[v]++;
        }

        for(int i=0; i<m.size(); i++){
            int v = m[i]-'0';
            mm[v]++;
        }

        int maxx=0;

        for(int i=0; i<=9; i++)
        {
            int cs = ss[i];
            int tm = cs;

            if(cs==0)continue;

            for(int j=i+1; j<=9 && cs>0; j++){
                if(cs<=mm[j]){
                    mm[j]-=cs;
                    cs=0;
                }
                else{
                    cs-=mm[j];
                    mm[j]=0;
                }
            }

            maxx += (tm-cs);
        }

        printf("%d\n",minn);
        printf("%d\n",maxx);
    }
    return 0;
}

