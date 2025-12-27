#include<bits/stdc++.h>
using namespace std;
string ss,tt;
int vis[200];
int main()
{
    while(cin>>ss>>tt)
    {
        if(ss==tt){
            printf("0\n");
            continue;
        }

        map<char,char>mp;
        for(char ch='a'; ch<='z'; ch++){
            mp[ch] = ch;
        }

        memset(vis,0,sizeof(vis));
        for(int i=0; i<ss.size(); i++){
            char cs = ss[i];
            char ct = tt[i];
            if(vis[cs]==0 && vis[ct]==0)mp[cs] = ct;
            if(vis[ct]==0 && vis[cs]==0)mp[ct] = cs;

            vis[cs]=1;
            vis[ct]=1;
        }

        string tm = tt;

        for(int i=0; i<tm.size(); i++){
            tm[i] = mp[tm[i]];
        }

        if(ss!=tm){
            printf("-1\n");
            continue;
        }

        memset(vis,0,sizeof(vis));
        vector<char>ans;
        for(int i=0; i<ss.size(); i++){
            if(ss[i]!=tt[i]){
                if(vis[ss[i]]==0 && vis[tt[i]]==0){
                    ans.push_back(ss[i]);
                    ans.push_back(tt[i]);
                    vis[ss[i]]=1;
                    vis[tt[i]]=1;
                }
            }
        }

        int cnt = ans.size()/2;
        printf("%d\n",cnt);

        for(int i=0; i<ans.size();i+=2)
        {
            printf("%c %c\n",ans[i],ans[i+1]);
        }
    }

    return 0;
}
