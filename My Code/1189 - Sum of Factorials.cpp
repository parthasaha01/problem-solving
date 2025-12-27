#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<ll, int>
ll fac[21];
int solve(ll n)
{
    int mask = 0;
    for(int i=20; i>=0; i--)
    {
        if(fac[i]<=n) {
            n -= fac[i];
            mask = (mask|(1<<i));
        }
        if(n==0)return mask;
    }
    return -1;
}
int main()
{
    fac[0]=1;
    for(int i=1; i<=20; i++){
        fac[i]=fac[i-1]*i;
    }

    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n; scanf("%lld",&n);

        int mask = solve(n);

        if(mask==-1){
            printf("Case %d: impossible\n",ks);
        }
        else{
            printf("Case %d: ",ks);

            for(int i=0,flag=0; i<20; i++){
                if(mask&(1<<i)){
                    if(flag)printf("+%d!",i);
                    else printf("%d!",i);
                    flag = 1;
                }
            }
            printf("\n");
        }
    }

    return 0;
}

/*

It is possible to use a greedy approach:
since fact(n) > fact(0)+fact(1)+...+fact(n-1) (this is true for each n > 2)
you can iterate from the greatest factorial(20!) to the smallest one,
if fact[i] is less than or equal to N you must take it, decrease N by fact[i]
and proceed with the next factorial. At the end, if N is 0,
you found the solution, otherwise it is impossible to obtain N adding factorials.

*/
