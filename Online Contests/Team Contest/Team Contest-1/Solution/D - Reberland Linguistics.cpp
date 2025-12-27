#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int sz=s.size();

        set<string>res;
        map<string,bool>mp;

        for(int i=sz-2; i>=0; i--)
        {
            if(i!=sz-3)
            {
                if(i+6<=sz-1)
                {
                    if(s.substr(i+2,2)==s.substr(i+4,2) && s.substr(i+2,3)==s.substr(i+5,3)){
                        continue;
                    }
                }
                else if(i+4<=sz-1)
                {
                    if(s.substr(i+2,2)==s.substr(i+4,2)){
                        continue;
                    }
                }
                string s1=s.substr(i,2);
                res.insert(s1);
            }
        }
        for(int i=5; i<sz-2; i++)
        {
            if(i!=sz-4)
            {
                if(i+6<=sz-1)
                {
                    if(s.substr(i+2,2)==s.substr(i+4,2) && s.substr(i+2,3)==s.substr(i+5,3)){
                        continue;
                    }
                }
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

/*
abcdexyzzzz
abcdexyzzzzpq
abcdexyzzzzzz
abcdexyzzzxzzz
abcdexyzzzzxzzz
abcdexyzzzzxzzzzzzzzz
*/
