#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,r;

    cin>>s>>t;

    r = s;
    reverse(r.begin(),r.end());

    if(r==t)printf("YES\n");
    else printf("NO\n");

    return 0;
}
