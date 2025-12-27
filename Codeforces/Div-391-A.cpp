#include<bits/stdc++.h>
using namespace std;
int fr[200];
int main()
{
    string s;

    while(cin>>s)
    {
        memset(fr,0,sizeof(fr));

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='B'){
                fr[1]++;
            }
            else if(s[i]=='b'){
                fr[2]++;
            }
            else if(s[i]=='l'){
                fr[3]++;
            }
            else if(s[i]=='s'){
                fr[4]++;
            }
            else if(s[i]=='r'){
                fr[5]++;
            }
            else if(s[i]=='a'){
                fr[6]++;
            }
            else if(s[i]=='u'){
                fr[7]++;
            }
        }

        int ans = 1000000000;

        ans = min(ans,fr[1]);
        ans = min(ans,fr[2]);
        ans = min(ans,fr[3]);
        ans = min(ans,fr[4]);
        ans = min(ans,fr[5]);
        ans = min(ans,fr[6]/2);
        ans = min(ans,fr[7]/2);

        printf("%d\n",ans);
    }

    return 0;
}
