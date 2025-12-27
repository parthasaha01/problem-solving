#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
int main()
{
    //while(1)
    {
        int a,b; scanf("%d%d",&a,&b);
        int ans = 0;
        while(a<=b)
        {
            a=a*3;
            b=b*2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

