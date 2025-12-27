#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int k;
        scanf("%d",&k);
        for(int i=0; i<k; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i]=y-x-1;
        }
        int ans=0;
        for(int i=0; i<k; i++)
        {
            ans=ans^a[i];
        }

        if(ans>0)
            printf("Case %d: Alice\n",ks);
        else
            printf("Case %d: Bob\n",ks);
    }

    return 0;
}
