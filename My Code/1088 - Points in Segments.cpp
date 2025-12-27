#include<bits/stdc++.h>
using namespace std;
#define mx 100000
int a[mx+5];
int BinarySearch(int v,int n)
{
    if(v<a[0]) return 0;

    int lo=0;
    int hi=n-1;
    int ans=0;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        ans=md;

        if(a[md]==v){
            lo=md+1;
        }
        else if(a[md]>v){
            hi=md-1;
        }
        else{
            lo=md+1;
        }
    }

    if(a[ans]>v) return ans;
    return ans+1;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n,q;
        scanf("%d%d",&n,&q);

        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        printf("Case %d:\n",ks);

        for(int i=0; i<q; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);

            int cnt1=BinarySearch(x-1,n);
            int cnt2=BinarySearch(y,n);
            int cnt=cnt2-cnt1;
            printf("%d\n",cnt);
        }
    }

    return 0;
}
