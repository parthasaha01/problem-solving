#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n;
        scanf("%d",&n);

        int rev=0;
        int n1=n;

        while(n1!=0)
        {
            rev=(rev*10)+(n1%10);
            n1=n1/10;
        }

        if(rev==n)
            printf("Case %d: Yes\n",kase);
        else
            printf("Case %d: No\n",kase);
    }

    return 0;
}
