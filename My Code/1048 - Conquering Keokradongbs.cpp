#include<bits/stdc++.h>
using namespace std;
vector<int>res;
int a[1005],n,k;
bool check(int v)
{
    int d = 1;
    int s = 0;

    for(int i=1; i<=n; i++){
        if(a[i]>v){
            d = 1000000;
            break;
        }
        if(s+a[i]<=v){
            s += a[i];
        }
        else{
            d++;
            s = a[i];
        }
    }

    if(d>k) return false;
    else return true;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        scanf("%d %d",&n,&k);
        int mx = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        int lo = 1;
        int hi = 100000000;
        int ans = 0;

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

        if()

    }

    return 0;
}
