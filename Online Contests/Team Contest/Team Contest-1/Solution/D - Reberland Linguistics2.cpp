
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int sz=s.size();

        set<string>res;

        for(int i=5; i<sz-1; i++)
        {
            if(i!=sz-3)
            {
                string s1=s.substr(i,2);
                res.insert(s1);
            }
        }
        for(int i=5; i<sz-2; i++)
        {
            if(i!=sz-4)
            {
                string s1=s.substr(i,3);
                res.insert(s1);
            }
        }

        int cnt=res.size();
        cout << cnt << endl;

        set<string>::iterator it;

        for(it=res.begin(); it!=res.end(); it++)
        {
            cout << (*it) << endl;
        }
    }

    return 0;
}
