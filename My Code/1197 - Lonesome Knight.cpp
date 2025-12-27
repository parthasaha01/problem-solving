#include<bits/stdc++.h>
using namespace std;
int fx[]={-2,-2,-1,-1,+1,+1,+2,+2};
int fy[]={-1,+1,-2,+2,-2,+2,-1,+1};
int main()
{
    int t; cin>>t;
    for(int ks=1; ks<=t; ks++)
    {
        string s; cin>>s;
        int x = s[0]-'a'+1;
        int y = s[1]-'0';

        int ans = 0;
        for(int k=0; k<8; k++)
        {
            int xx = x+fx[k];
            int yy = y+fy[k];
            if(xx>=1&&xx<=8&&yy>=1&&yy<=8)++ans;
        }

        cout << ans << endl;
    }
    return 0;
}
