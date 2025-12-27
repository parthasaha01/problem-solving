#include<bits/stdc++.h>
using namespace std;
int vis[30];
int main()
{
    string ss;
    cin>>ss;

    //sort(ss.begin(),ss.end());

    char cur='a';
    for(int i=0; i<ss.size(); i++){
        if(ss[i]>cur){
            printf("NO");
            return 0;
        }
        if(ss[i]==cur){
            cur++;
        }
    }

    for(int i=0; i<ss.size(); i++){
        vis[ss[i]-'a']=true;
    }

    int cnt=0;
    for(int i=0; i<26; i++){
        if(vis[i])cnt++;
    }

    int cn=0;
    for(int i=1; i<=cnt; i++){
        if(vis[i-1])cn++;
    }

    if(cn==cnt)printf("YES");
    else printf("NO");

    return 0;

}
