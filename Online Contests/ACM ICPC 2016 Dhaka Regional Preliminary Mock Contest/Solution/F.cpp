#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
//map<ll,ll>pid;
map<ll,ll>rid;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        //pid.clear();
        rid.clear();

        int q;
        scanf("%d",&q);

        for(int k=1; k<=q; k++)
        {
            int typ;
            ll pd,rd;
            scanf("%d",&typ);

            if(typ==1)
            {
                scanf("%llu%llu",&pd,&rd);

                if(rid[rd]==0)
                {
                    printf("Y\n");
                    rid[rd]=pd;
                    //pid[pd]=rd;
                }
                else
                {
                    printf("N\n");
                }
            }
            else
            {
                scanf("%llu",&rd);
                if(rid[rd]==0)
                {
                    printf("F\n");
                }
                else
                {
                    printf("%llu\n",rid[rd]);
                    rid[rd]=0;
                }
            }
        }
    }

    return 0;
}
