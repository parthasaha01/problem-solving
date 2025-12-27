#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll s[100005];
bool cmp(ll x, ll y)
{
    return x>y;
}
int main()
{
    ll n; cin>>n;

    for(int i=1; i<=n; i++)
    {
       scanf("%I64d",&a[i]);
       s[a[i]]++;
    }

    sort(a+1, a+n+1,cmp);

    ll maxx = 0;

    for(int i=1; i<=n; i++)
    {
        maxx = max(maxx,a[i]);
    }

    ll cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(a[i]==maxx)cnt++;
    }

    if((cnt%2)==1){
        cout << "Conan" << endl;
    }
    else{
        if(cnt==n)cout << "Agasa" << endl;
        else
        {
            for(int i=1; i<=n; i++)
            {
                if((s[a[i]]%2)==1){
                        cout << "Conan" << endl;
                    return 0;
                }
            }


            cout << "Agasa" << endl;

        }

    }


    //printf("%I64d\n",ans);
   // cout << ans << endl;

    //main();

    return 0;
}

