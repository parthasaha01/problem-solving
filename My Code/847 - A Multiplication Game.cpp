#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
int fun(ll p)
{
    if(p>=n) return 1;
    int chk=0;
    for(int i=9; i>=2&&chk!=1; i--){
        chk=(chk)||(fun(p*i));
    }
    return chk^1;
}

int main()
{
    while(scanf("%lld",&n)==1)
    {
        int ans=fun(1);
        if(ans==0) printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }
    return 0;
}
