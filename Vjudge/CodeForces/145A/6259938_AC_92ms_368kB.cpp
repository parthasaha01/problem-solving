#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;

    while(cin >> a >> b)
    {
        int four=0,seven=0;
        int sz=a.size();
        for(int i=0; i<sz; i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]=='4'){
                    ++four;
                }
                else
                {
                    ++seven;
                }
            }
        }

        int res = min(four,seven) + abs(seven-four);

        cout << res << endl;
    }

    return 0;
}
