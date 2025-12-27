#include<bits/stdc++.h>
using namespace std;
string s[1000];
int main()
{
    int t,n,cnt,flag,res;

    scanf("%d",&t);

    for(int test=1; test<=t; test++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            cin >> s[i];
        }
        cnt=flag=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]!="W")
            {
                ++cnt;
                if(cnt==3)
                {
                    flag=1;
                    res=i+1;
                    break;
                }
            }
            else
                cnt=0;
        }
        if(flag)
            printf("Case %d: %d\n",test,res);
        else
            printf("Case %d: Yay! Mighty Rafa persists!\n",test);
    }

    return 0;
}
