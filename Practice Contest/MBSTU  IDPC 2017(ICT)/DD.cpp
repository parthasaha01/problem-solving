#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a[1005],b[1005],c[1005],A,B,C,sum;
    set<ll>st;
    ll t,w = 0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&A,&B,&C,&sum);
        for(int i=0; i<A; i++)
            scanf("%lld",&a[i]);

        for(int i=0; i<B; i++)
            scanf("%lld",&b[i]);

        for(int i=0; i<A; i++)
            for(int j = 0; j<B; j++)
            {
                ll x = sum - a[i] - b[j];
                //cout<<"x = "<<x<<endl;
                if(x>=0)
                    st.insert(x);
            }
        int ck = 0;
        for(int i=0; i<C; i++)
        {
            scanf("%lld",&c[i]);
            ll w = c[i];
            if(st.find(w)!=st.end())
                ck = 1;
        }
        if(ck)
            printf("Case %lld: YES\n",++w);
        else
            printf("Case %lld: NO\n",++w);
        st.clear();
    }

}

/*

2
2 2 2 8
1 2
2 3
3 4
2 2 2 8
1 2
 2 3
 6 7

 */
