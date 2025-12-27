#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T,test,nr,k;
    ll L,R,orr,andd,n;

    scanf("%d",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%lld %lld",&L,&R);

        nr = log2(R)+1;

        if(L==R){
            orr=L;
            andd=L;
        }
        else{
            orr=0;
            for(k=nr-1; k>=0; k--){
                n=1LL<<k;

                if((L&n)==(R&n)){
                    if(((R&n)>>k)==1){
                        orr |= n;
                    }
                }
                else{
                    andd=orr;
                    orr+=(n<<1LL)-1;
                    break;
                }

            }
        }

        printf("Case %d: %lld %lld\n",test,orr,andd);
    }


    return 0;
}
