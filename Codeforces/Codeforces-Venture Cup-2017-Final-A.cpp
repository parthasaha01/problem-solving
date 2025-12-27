#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int m,d;
    while(cin>>m>>d)
    {
        int v = month[m];
        int ans = 0;
        if(v==28)
        {
            if(d==1) ans = 4;
            else ans = 5;
        }
        else if(v==30)
        {
            if(d==7) ans = 6;
            else ans = 5;
        }
        else
        {
            if(d==6||d==7)ans = 6;
            else ans = 5;

        }

        cout << ans << endl;
    }

    return 0;
}
