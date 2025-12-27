#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long int ca,cb,cnt,a,b,sz,res;

    while(cin >> s)
    {
        sz=s.size();
        a=0;
        cb=0;

        for(long int i=0; i<sz; i++)
        {
            if(s[i]=='('){
                a++;
            }
            else
            {
                if(a>0)
                {
                    a--;
                    cb++;
                }
            }
        }

        res = cb*2;

        cout << res << endl;
    }

    return 0;
}
