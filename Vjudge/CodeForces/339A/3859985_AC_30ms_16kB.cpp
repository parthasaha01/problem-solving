#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while(cin >> s)
    {
        int len=s.size();

        for(int i=0; i<len; i+=2)
        {
            for(int j=0; j<len-i-2; j+=2)
            {
                if(s[j]>s[j+2]){
                    swap(s[j],s[j+2]);
                }
            }
        }

        cout << s << endl;
    }

    return 0;
}
