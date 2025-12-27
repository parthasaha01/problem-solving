#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;
ll a[100005];
bool cmp(ll x, ll y){
    return x>y;
}
int main()
{
    ll n,k;

    while(scanf("%I64d%I64d",&n,&k)==2)
    {
        for(int i=0; i<n; i++){
            scanf("%I64d",&a[i]);
        }

        //sort(a,a+n);
        sort(a,a+n,cmp);

        for(int i=0; i<n; i++)
        {
            ll item = a[i]*k;
            ll sz = v.size();
            ll low=0, high=sz-1;
            bool found=false;

            while(low<=high)
            {
                ll mid = (low+high)/2;

                if(v[mid]==item){
                    found=true;
                    break;
                }
                else if(v[mid]<item){
                    high=mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            if(found==false){
                v.push_back(a[i]);
            }
        }

        ll res = v.size();

        printf("%I64d\n",res);

        v.clear();
    }

    return 0;
}
