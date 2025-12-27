#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll ss[mx],cum[mx];
bool cmp(int x,int y){
    return x>y;
}
//int check(ll k)
//{
//    int flag = 0;
//    for(int i=1; i<=n; i++)
//    {
//        int j = i+k-1;
//        if(j>n)break;
//
//        ll sum = cum[j]-cum[]
//    }
//}
int main()
{
    ll n,A,B;
    scanf("%I64d %I64d %I64d",&n,&A,&B);

   // cum[0]=0;
   ll tot = 0;
    for(int i=1; i<=n; i++){
        scanf("%I64d",&ss[i]);
        tot += ss[i];
        //cum[i] = cum[i-1]+ss[i];
    }

    if(n==1){
        printf("0\n");
        return 0;
    }

    ll uu = ss[1]*A;
    ll bb = tot*B;
    if(uu>=bb){
        printf("0\n");
        return 0;
    }

    sort(ss+2,ss+n+1,cmp);

    cum[0]=0;
    for(int i=1; i<=n; i++){
        cum[i] = cum[i-1]+ss[i];
    }

    ll ans = n;

    for(int i=1; i<n; i++){
        ll sum = cum[i+1]-cum[1];
        ll SS = tot-sum;
        ll vv = ss[1]*A;
        ll BS = B*SS;
        if(vv>=BS){
            ans = i;
            break;
        }
    }

//    ll lo = 0;
//    ll hi = n;
//    ll ans=n;
//    while(lo<=hi)
//    {
//        ll md = (lo+hi)/2;
//        if(check(md)==1){
//            ans = md;
//            hi = md-1;
//        }
//        else{
//            lo = md+1;
//        }
//    }

    printf("%I64d\n",ans);

    return 0;
}
