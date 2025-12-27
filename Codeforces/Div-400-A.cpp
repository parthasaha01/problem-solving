#include<bits/stdc++.h>
using namespace std;
string s,ss,mm,nn;
int main()
{
    cin >> s >> ss;
    cout << s << " " << ss << endl;
    int n; cin >>n;

    for(int i=1; i<=n; i++)
    {
        cin >> mm >> nn;

        if(mm==s)
        {
            s=nn;
        }
        else
        {
            ss=nn;
        }

        cout << s << " " << ss << endl;
    }

    return 0;
}
