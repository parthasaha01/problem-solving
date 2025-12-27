#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {



        int cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
            {
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]=='0')
                    {
                        cnt++;
                    }
                }

                break;
            }
        }

        if(cnt>=6)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }

    }

    return 0;
}
