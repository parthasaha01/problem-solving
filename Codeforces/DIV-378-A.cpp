#include<bits/stdc++.h>
using namespace std;
string ss;
int main()
{
    map<char,int>mp;
    mp['A']=1;
    mp['E']=1;
    mp['I']=1;
    mp['O']=1;
    mp['U']=1;
    mp['Y']=1;

    while(cin>>ss)
    {
        int b=-1,d;
        int maxx=0;
        for(int i=0; i<ss.size(); i++)
        {
            if(mp[ss[i]])
            {
                d=abs(i-b);
                b=i;
                maxx=max(maxx,d);
            }
        }

        d=abs(ss.size()-b);
        maxx=max(maxx,d);

        printf("%d\n",maxx);
    }

    return 0;
}
