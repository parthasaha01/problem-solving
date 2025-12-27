#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll L,R,Q;
    cin>>L>>R>>Q;

    if(Q>R){
        printf("infinity\n");
        return 0;
    }

    ll ans = 0;

    ll sq = sqrt(Q);
    for(ll i=1; i<=sq; i++){
        if(Q%i==0){
            ans+=2;
        }
    }

    if(sq*sq==Q)ans--;

    cout << ans << endl;

    //main();

    return 0;
}
