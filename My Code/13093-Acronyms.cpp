#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss,dd;
    while(getline(cin,ss))
    {
        getline(cin,dd);

        string s;
        string d;

        s+=tolower(ss[0]);
        d+=tolower(dd[0]);

        for(int i=0; i<ss.size(); i++)
        {
            if(ss[i-1]==' ' && isalpha(ss[i])){
                s+=tolower(ss[i]);
            }
        }
        for(int i=0; i<dd.size(); i++)
        {
            if(dd[i-1]==' ' && isalpha(dd[i])){
                d+=tolower(dd[i]);
            }
        }

        if(s==d) cout << "yes" << endl;
        else cout << "no" << endl;

    }

    return 0;
}
