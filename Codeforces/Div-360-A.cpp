#include<bits/stdc++.h>
using namespace std;
string s[105];
char ss[105];
int main()
{
    int n,d,maxx,cnt;

    while(cin >> n >> d)
    {
        for(int i=0; i<d; i++)
        {
            cin >> s[i];
        }

        for(int i=0; i<n; i++)
        {
            ss[i]='1';
        }
        ss[n]='\0';
        maxx=0;
        cnt=0;
        for(int i=0; i<d; i++)
        {
            if(s[i]==ss)
            {
                maxx = max(maxx,cnt);
                cnt=0;
            }
            else
            {
                ++cnt;
            }
        }

        maxx = max(maxx,cnt);
        cnt=0;

        cout << maxx << endl;
    }

    return 0;
}
