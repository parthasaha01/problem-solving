#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[10000005];

int main()
{
    int tt; scanf("%d",&tt);

    for(ll i=1; i<=10000000; i++)
    {
        sum[i] = (i*(i+1))/2;
    }

    for(int ks=1; ks<=tt; ks++)
    {
        ll N; scanf("%lld",&N);
        ll NN = 2*N;

        ll ans = 0;

        for(ll i=1; i<=10000000; i++)
        {
            ll lob = N - sum[i];
            if(lob<0)break;
            ll hor = (i+1);
            //if(lob<0)lob*=(-1);
            if(((lob%hor)==0) && ((lob/hor)!=0)){
                ans++;

                //printf("%lld %lld\n",lob/hor,i+1);
            }
        }
        //cout << endl;

        printf("Case %d: %lld\n",ks,ans);

    }
    return 0;
}
