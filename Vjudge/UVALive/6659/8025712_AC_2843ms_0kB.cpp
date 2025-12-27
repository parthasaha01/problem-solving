#include<bits/stdc++.h>
using namespace std;
string ss;
int fr[30];
bool valid()
{
    int ln = 0;
    int od = 0;
    for(int i=0; i<26; i++){
        if(fr[i]%2==1)od++;
        ln += fr[i];
    }

    if(ln%2==0 && od==0)return true;
    if(ln%2==1 && od==1)return true;
    return false;
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        cin>>ss;
        int ans = 0;
        for(int i=0; i<ss.size(); i++)
        {
            memset(fr,0,sizeof(fr));
            for(int j=i; j<ss.size(); j++){
                int ch = ss[j]-'a';
                fr[ch]++;
                if(valid()==true)ans++;
            }
        }

        printf("Case %d: %d\n",ks,ans);
    }
}
