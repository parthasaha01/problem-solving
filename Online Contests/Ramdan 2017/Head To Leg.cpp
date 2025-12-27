#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int hh,gg; scanf("%d%d",&hh,&gg);

        int hen=0;
        int cow=0;

        int lo=0;
        int hi=hh;

        while(lo<=hi)
        {
            int md=(lo+hi)/2;

            int ct = 4*md;
            int ht = 2*(hh-md);

            int ss = ct+ht;

            if(ss==gg)
            {
                cow=md;
                hen=(hh-cow);
                lo=md+1;
            }
            else if(ss<gg)
            {
                lo=md+1;
            }
            else
            {
                hi=md-1;
            }
        }

        printf("Case %d: %d %d\n",ks,hen,cow);
    }
    return 0;
}
