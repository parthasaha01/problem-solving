#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r,a;
    scanf("%d%d%d",&l,&r,&a);

    int maxx = 0;

    for(int x=1; x<=150; x++)
    {
        int lx,rx,ax;
        lx = l, rx= r, ax = a;

        bool flag = false;

        if(lx>=x)
        {
            if(rx>=x)
            {
                maxx = max(maxx,x+x);
            }
            else
            {
                if(rx+ax>=x)
                {
                    maxx = max(maxx,x+x);
                }
            }
        }
        else if(lx+ax>=x)
        {
            ax = ax - (x-lx);
            if(rx>=x)
            {
                maxx = max(maxx,x+x);
            }
            else
            {
                if(rx+ax>=x)
                {
                    maxx = max(maxx,x+x);
                }
            }
        }
    }

    printf("%d\n",maxx);

    //main();

    return 0;
}
