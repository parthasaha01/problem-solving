#include<bits/stdc++.h>
using namespace std;
int START[150],END[150];
string ss;
int n,k;
int fun()
{
    int sz = ss.size();
    int cnt=0;

    for(int i=0; i<sz; i++)
    {
        int d = ss[i];
        if(START[d]==i)
        {
            cnt++;
        }

        if(cnt>k)
        {
            return 1;
        }

        if(END[d]==i)
        {
            cnt--;
        }
    }

    return 0;
}
int main()
{
    while(cin>>n>>k)
    {
        cin>>ss;

        memset(START,-1,sizeof(START));
        memset(END,-1,sizeof(END));

        int sz = ss.size();

        for(int i=0; i<sz; i++)
        {
            int d = ss[i];
            if(START[d]==-1)
            {
                START[d]=i;
            }
        }

        for(int i=sz-1; i>=0; i--)
        {
            int d = ss[i];
            if(END[d]==-1)
            {
                END[d]=i;
            }
        }

        int ans = fun();

        if(ans){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
