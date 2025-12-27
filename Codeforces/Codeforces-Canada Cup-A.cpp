#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    while(cin>>n)
    {
        cin>>s;
        int cnt1=0;
        int p1=0;
        int sz=s.size();
        while(s[p1]=='<'&&p1<sz)
        {
            cnt1++;
            p1++;
        }

        int p2=s.size()-1;
        int cnt2=0;

        while(s[p2]=='>'&&p2>=0)
        {
            cnt2++;
            p2--;
        }

        int ans=cnt1+cnt2;
        cout << ans << endl;

    }

    return 0;
}
