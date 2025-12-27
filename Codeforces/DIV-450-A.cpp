#include<bits/stdc++.h>
using namespace std;
int main()
{


    int n;

    while(scanf("%d",&n)==1)
    {
        int pos,neg;
        pos=neg=0;

        for(int i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            if(x<0)neg++;
            else pos++;
        }

        if(neg<=1 || pos<=1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
