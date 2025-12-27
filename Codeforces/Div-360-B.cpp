#include<bits/stdc++.h>
using namespace std;
string s1,s2,s;
int main()
{
    while(cin >> s1)
    {
        s2=s1;
        reverse(s2.begin(),s2.end());

        s= s1+s2;

        cout << s << endl;
    }

    return 0;
}
