#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {


        int h1 = s[0]-'0';
        int h2 = s[1]-'0';
        int m1 = s[3]-'0';
        int m2 = s[4]-'0';

        int ans = 0;

        while(1)
        {
            if(h1==m2&&h2==m1)
            {
                break;
            }

            int m = (m1*10)+m2;
            int h = (h1*10)+h2;

            m++;
            if(m==60)
            {
                m=0;
                h++;
            }
            if(h==24)
            {
                h=0;
            }

            m1 = m/10;
            m2 = m%10;
            h1 = h/10;
            h2 = h%10;

            ans++;
        }

        printf("%d\n",ans);

    }

    return 0;
}
