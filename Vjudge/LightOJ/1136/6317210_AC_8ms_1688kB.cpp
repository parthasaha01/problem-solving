#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);

    ll a,b,cnt,cnt1,cnt2;

    for(int kase=1; kase<=t; kase++)
    {
        scanf("%lld%lld",&a,&b);

        if(a>b)
            swap(a,b);

        a=a-1;

        if(a%3==0){
            cnt1 = (a/3)*2;
        }
        else if(a%3==1){
            cnt1 = (a/3)*2;
        }
        else{
            cnt1 = ((a/3)*2)+1;
        }

        if(b%3==0){
            cnt2 = (b/3)*2;
        }
        else if(b%3==1){
            cnt2 = (b/3)*2;
        }
        else{
            cnt2 = ((b/3)*2)+1;
        }

        cnt=cnt2-cnt1;

        printf("Case %d: %lld\n",kase,cnt);
    }

    return 0;
}
