#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        int present=0;
        int maxx=0;
        for(int i=1; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            present-=y;
            present+=x;
            if(present>maxx){
                maxx=present;
            }
        }
        printf("Case %d: %d\n",ks,maxx);
    }

    return 0;
}
