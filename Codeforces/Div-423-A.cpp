#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
int n,x,y,a[mx+5];
int main()
{
    while(scanf("%d%d%d",&n,&x,&y)==3)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);

        }

        int ans=0;
        int one=x;
        int half=0;
        int two=y;

        for(int i=1; i<=n; i++)
        {
            if(a[i]==1)
            {
                if(one>0)
                {
                    one--;
                }
                else if(two>0)
                {
                    two--;
                    half++;
                }
                else if(half>0)
                {
                    half--;
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                if(two>0)
                {
                    two --;
                }
                else
                {
                    ans += 2;
                }
            }

        }

        printf("%d\n",ans);
    }
    return 0;
}
