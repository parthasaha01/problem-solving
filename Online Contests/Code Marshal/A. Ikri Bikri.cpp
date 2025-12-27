#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        ll l,n;
        //cin >> l >> n;
        scanf("%lld%lld",&l,&n);

        ll res = l-n-1;
        printf("Case %d: %lld\n",kase,res);
        //cout << "Case " << kase << ": " << res << endl;
    }

    return 0;
}
