#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    while(cin>>n)
    {
        cin>>s;

        int sx = n+1;
        int sy = n+1;
        int ex = n+1;
        int ey = n+1;
        int cnt = 0;
        int ct = 0;
        int px=n+1;
        int py=n+1;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='L'){
                ex --;
            }
            else if(s[i]=='R'){
                ex++;
            }
            else if(s[i]=='U'){
                ey++;
            }
            else if(s[i]=='D'){
                ey--;
            }

            ct++;
            int ds = abs(ex-sx) + abs(ey-sy);

            if(ct>ds){
                sx = px;
                sy = py;
                cnt++;
                ct = 0;
            }
            px = ex;
            py = ey;
        }

        cnt++;
        printf("%d\n",cnt);
    }

    return 0;
}
