#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx];
int main()
{
    ll n,u;
    scanf("%I64d %I64d",&n,&u);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
    }

    ll res = -1000000000000000002;
    double ans = -1000000000000000.0;
    bool flag = false;

    for(int k=3; k<=n; k++)
    {
        ll ek,ei,ej;
        ek = a[k];
        ll nd = ek-u;

        int lo = 1;
        int hi = n;
        int pos = k-2;
        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            if(a[md]>=ek){
                hi = md-1;
            }
            else if(a[md]<nd){
                lo = md+1;
            }
            else{
                pos = md;
                hi = md-1;
            }
        }

        if(k==(pos+1)){
            pos--;
        }

        if(a[k]-a[pos]>u)continue;

        flag = true;
        ei = a[pos];
        ej = a[k-1];



        double cnt = ((double)ek-(double)ej)/((double)ek-(double)ei);
        if(cnt>ans)ans = cnt;

        if(k==9){
            cout << ei << " " << ej << " " << ek << endl;
            cout << cnt << endl;
        }
    }

    if(flag)cout << ans << endl;
    else printf("-1\n");

    return 0;
}
