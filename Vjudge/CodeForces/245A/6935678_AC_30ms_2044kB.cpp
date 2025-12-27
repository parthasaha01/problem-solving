#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {
        int xa[3],ya[3];
        xa[1]=xa[2]=ya[1]=ya[2]=0;

        for(int i=0; i<n; i++){
            int t,x,y;
            scanf("%d%d%d",&t,&x,&y);
            xa[t]+=x;
            ya[t]+=y;
        }

        for(int i=1; i<=2; i++){
            if(xa[i]>=ya[i])
                printf("LIVE\n");
            else
                printf("DEAD\n");
        }
    }

    return 0;
}
