#include<bits/stdc++.h>
using namespace std;
int fr[30];
string ss;
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
            for(int j=i; j<ss.size(); j++)
            {
                int ln = j-i+1;
                int od=0;
                int ev=0;

                int ch = ss[j]-'a';
                fr[ch]++;

                for(int i=0; i<26; i++){
                    if(fr[i]%2==0)ev++;
                    else od++;
                }

                if(ln%2==0){
                    if(od==0)ans++;
                }
                else{
                    if(od==1)ans++;
                }

            }
        }

        printf("Case %d: %d\n",ks,ans);
    }

    return 0;
}
