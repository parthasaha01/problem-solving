#include<bits/stdc++.h>
using namespace std;
int sq[1005];
int main()
{
    for(int i=0; i<=1000; i++)
    {
        sq[i] = i*i;
    }

    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        //int z; scanf("%d",&z);

        for(int z=0; z<=100; z++)
        {
            int ans = 1000000000;
            for(int i=0; i<=1000; i++)
            {
                int y = sq[i];
                int x = z-y;
                int d = abs(x-y);
                ans = min(ans,d);

                //printf("x=%d y=%d z=%d d=%d ans=%d\n",x,y,z,d,ans);
                //getchar();
            }
            printf("%d = %d\n",z,ans);
        }

    }
    return 0;
}

