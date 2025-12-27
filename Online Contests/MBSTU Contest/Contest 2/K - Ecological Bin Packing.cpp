#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[6][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
    long int x[3],y[3],z[3];

    while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&x[0],&x[1],&x[2],&y[0],&y[1],&y[2],&z[0],&z[1],&z[2])==9)
    {
        long int mov;
        long int minn = 1000000000;
        int flag;

        mov=0;
        mov = x[1]+x[2]+y[0]+y[1]+z[0]+z[2]; // BCG
        if(mov<minn){
            minn=mov;
            flag=0;
        }

        mov=0;
        mov = x[1]+x[2]+y[0]+y[2]+z[0]+z[1]; // BGC
        if(mov<minn){
            minn=mov;
            flag=1;
        }

        mov=0;
        mov = x[0]+x[1]+y[1]+y[2]+z[0]+z[2];    // CBG
        if(mov<minn){
            minn=mov;
            flag=2;
        }

        mov=0;
        mov = x[0]+x[1]+y[0]+y[2]+z[1]+z[2];    //CGB
        if(mov<minn){
            minn=mov;
            flag=3;
        }

        mov=0;
        mov = x[0]+x[2]+y[1]+y[2]+z[0]+z[1];    //GBC
        if(mov<minn){
            minn=mov;
            flag=4;
        }

        mov=0;
        mov = x[0]+x[2]+y[0]+y[1]+z[1]+z[2];    //GCB
        if(mov<minn){
            minn=mov;
            flag=5;
        }

        printf("%s %ld\n",s[flag],minn);
    }

    return 0;
}

