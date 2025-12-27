#include<bits/stdc++.h>
using namespace std;
set<char>ss;
string s;
int main()
{
    int n; scanf("%d",&n);
    cin>>s;
    int maxx=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            int sz = ss.size();
            maxx = max(maxx,sz);
            ss.clear();
        }
        else
        {
            ss.insert(s[i]);
        }
    }

    int sz = ss.size();
    maxx = max(maxx,sz);
    ss.clear();

    printf("%d\n",maxx);

    return 0;
}
