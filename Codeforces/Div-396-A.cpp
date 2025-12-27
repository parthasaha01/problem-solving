#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int main()
{
    string s,ss;

    while(cin>>s>>ss)
    {
        if(s==ss)printf("-1\n");
        else printf("%d\n",max(s.size(),ss.size()));
    }

    return 0;
}
