#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);

    ll n,cnt;

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld",&n);
        cnt=0;
        while(n!=0)
        {
            if(n%2==1){
                cnt++;
            }

            n/=2;
        }

        if(cnt%2==1)
            printf("Case %d: odd\n",kase);
        else
            printf("Case %d: even\n",kase);
    }

    return 0;
}
