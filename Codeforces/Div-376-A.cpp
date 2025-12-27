#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while(cin>>s)
    {
        int cnt=0;
        int p=0;
        for(int i=0; i<s.size(); i++)
        {
            int c=s[i]-'a';

            if(c>p)
            {
                int m1=abs(c-p);
                int m2=p+abs(26-c);
                cnt+=min(m1,m2);
            }
            else if(c<p)
            {
                int m1=abs(p-c);
                int m2=abs(26-p)+c;
                cnt+=min(m1,m2);
            }
            p=c;

        }

        printf("%d\n",cnt);
    }

    return 0;
}
