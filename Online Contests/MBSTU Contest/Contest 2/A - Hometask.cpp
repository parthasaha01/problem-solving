#include<bits/stdc++.h>
using namespace std;
string ss[15];
string s;
int main()
{
    int k,sz,cnt,cn1,cn2;
    char a,b;

    while(cin >> s)
    {
        sz = s.size();
        cin >> k;

        for(int i=0; i<k; i++)
        {
            cin >> ss[i];
        }

        cnt=0;

        for(int i=0; i<k; i++)
        {
            a=ss[i][0];
            b=ss[i][1];
            cn1=0;
            cn2=0;
            for(int i=0; i<sz; i++)
            {
                if(s[i]==a || s[i]==b)
                {
                    if(s[i]==a)
                    {
                        ++cn1;
                    }
                    else
                    {
                        ++cn2;
                    }
                }
                else
                {
                    cnt += min(cn1,cn2);
                    cn1=0;
                    cn2=0;
                }

            }
            cnt += min(cn1,cn2);
        }

        cout << cnt << endl;
    }

    return 0;
}
