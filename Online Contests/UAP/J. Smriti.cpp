#include<bits/stdc++.h>
using namespace std;
int sq[1005],ans[2000005];
int main()
{
    ans[0]=0;
    ans[1]=1;
    int v = 0;
    int hh = 3;
    int f = 1;
    for(int n=2; n<=1000000; n++)
    {
        ans[n] = v;

        if(v==0 && f==0)
        {
            hh+=2;
            f=1;
        }
        if(v==hh && f==1)
        {
            //hh+=2;
            f = 0;
        }

        if(f==0){
            v--;
        }
        if(f==1){
            v++;
        }
    }

    int tt;
    scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int z; scanf("%d",&z);
        printf("%d\n",ans[z]);

//        for(int z=0; z<=100; z++)
//        {
//            int ans = 1000000000;
//            for(int i=0; i<=1000; i++)
//            {
//                int y = sq[i];
//                int x = z-y;
//                int d = abs(x-y);
//                ans = min(ans,d);
//
//                //printf("x=%d y=%d z=%d d=%d ans=%d\n",x,y,z,d,ans);
//                //getchar();
//            }
//            printf("%d = %d\n",z,ans);
//        }

    }
    return 0;
}
