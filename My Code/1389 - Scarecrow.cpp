#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='.'){
                ans++;
                i+=2;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
