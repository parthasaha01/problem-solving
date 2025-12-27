#include<bits/stdc++.h>
#define ll long long
#define mx 1000010
using namespace std;
ll mod = 1000000007;
ll crr[mx],brr[mx],arr[mx],cum[mx];

int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1;tst<=test;tst++)
    {

        ll s,sk;
        scanf("%lld%lld",&s,&sk);

        ll ans = s*sk;

        ll n;
        scanf("%lld",&n);

        memset(crr,0,sizeof(crr));
        memset(arr,0,sizeof(arr));
        memset(brr,0,sizeof(brr));
        memset(cum,0,sizeof(cum));
        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        ll sum=1;
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&brr[j]);
            crr[brr[j]]++;
        }
        cum[mx]=0;
        for(int i=mx-1;i>=1;i--)
        {
            cum[i-1]=cum[i]+crr[i-1];
        }


        sort(arr,arr+n);

        for(int i=0;i<n;i++)
        {
            ll mnn;
            mnn = ans/arr[i];
            mnn++;
//            if(ans%arr[i]==0){
//                mnn = ans/arr[i];
//                mnn++;
//            }
//            else{
//
//            }
//            double tot = ans;
//            double mn = tot/(double)arr[i];



//            if(mnn==mn)
//            {
//                mnn++;
//            }
            //cout<<mnn<<endl;
            if((cum[mnn]-i)<=0){
                sum = 0;
                break;
            }
            sum *= (cum[mnn]-i);
            sum%=mod;
        }
        printf("Case %d: %lld\n",tst,sum);
    }

    return 0;
}
