#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        map<string,int>mp;

        for(int i=1; i<=n; i++){
            cin>>s;
            mp[s]=1;
        }
        int cnt=0;
        for(int i=1; i<=m; i++){
            cin>>s;
            if(mp[s]==1){
                cnt++;
            }
        }


        if(n>m){
            printf("YES\n");
        }
        else if(m>n){
            printf("NO\n");
        }
        else{
            if(cnt%2==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }

    }
}
