#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll T,L,R,orr,andd;

    scanf("%lld",&T);

    for(ll test=1; test<=T; test++)
    {
        scanf("%lld %lld",&L,&R);

        ll nr = log2(R)+1LL;

        if(L==R){
            orr=L;
            andd=L;
        }
        else{
            orr=0LL;

            for(ll k=nr-1; k>=0LL; k--){
                ll bl=L>>k;
                ll br=R>>k;

                if(bl!=br){
                    andd=orr;
                    orr+=(1LL<<(k+1LL))-1LL;
                    break;
                }
                else{
                    if(bl&1){
                        orr+=(1LL<<k);
                    }
                }
            }
        }

        printf("Case %lld: %lld %lld\n",test,orr,andd);
    }


    return 0;
}
