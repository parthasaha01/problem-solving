#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int T,test,row,col;
    long long S,sqi,p;
    double sq;

    scanf("%ld",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%lld",&S);

        sq = sqrt(S);

        //printf("sq=%lf\n",sq);

        if(sq == (long int)(sq))
        {
            sqi = sq;

            if(sqi&1)
            {
                row=sqi;
                col=1;
            }
            else
            {
                row=1;
                col=sqi;
            }
        }
        else
        {
            sqi = sq+1;
            //printf("sqi=%lld\n",sqi);
            //q=sqi*sqi;
            //r=q-S;
            //p=r+1;
            p = (sqi*sqi)-S+1;
            //printf("q=%lld\nr=%lld\np=%lld\n",q,r,p);

            if(p==sqi)
            {
                row=sqi;
                col=sqi;
            }
            else if(p>sqi)
            {
                if(sqi&1)
                {
                    row=sqi-(p-sqi);
                    col=sqi;
                }
                else
                {
                    row=sqi;
                    col=sqi-(p-sqi);
                }
            }
            else    //p<sqi
            {
                if(sqi&1)
                {
                    row=sqi;
                    col=p;
                }
                else
                {
                    row=p;
                    col=sqi;
                }
            }
        }

        printf("Case %ld: %ld %ld\n",test,col,row);
    }

    return 0;
}
