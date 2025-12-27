#include<bits/stdc++.h>
using namespace std;
int a[1005],n,k;
vector<int>res;
bool check(int v)
{
    int tm=0;
    int cnt=1;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>v)return false;

        if(tm+a[i]<=v){
            tm+=a[i];
        }
        else{
            tm = a[i];
            cnt++;
        }

        if(cnt>k)return false;
    }

    return true;
}
void fun(int v)
{
    int cnt=1;
    int tm=0;
    for(int i=1; i<=n; i++)
    {
        if(tm+a[i]<=v){
            tm+=a[i];
        }
        else{
            res.push_back(tm);
            cnt++;
            tm = a[i];
        }

        if((n-i)<=(k-cnt)){
            res.push_back(tm);
            for(int j=i+1; j<=n; j++){
                res.push_back(a[j]);
            }
            break;
        }
    }
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d",&n,&k);
        n++,k++;
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);

        int lo=0;
        int hi=100000000;
        int ans=1000000000;

        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            if(check(md)){
                ans = md;
                hi  = md-1;
            }
            else{
                lo = md+1;
            }
        }

        res.clear();
        fun(ans);

        printf("Case %d: %d\n",ks,ans);
        for(int i=0; i<res.size(); i++)
            printf("%d\n",res[i]);
    }
    return 0;
}
