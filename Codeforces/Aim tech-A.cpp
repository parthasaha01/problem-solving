#include<bits/stdc++.h>
using namespace std;
int vis[30];
int main()
{
    string ss;
    int k;
    cin>>ss>>k;

    if(ss.size()<k){
        printf("impossible\n");
    }
    else{
        int cnt=0;
        for(int i=0; i<ss.size(); i++){
            int id=ss[i]-'0';
            if(vis[id]==0)cnt++;
            vis[id]=1;
        }

        if(cnt>=k)printf("0\n");
        else printf("%d\n",k-cnt);
    }

    return 0;
}
