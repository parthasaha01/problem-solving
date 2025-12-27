#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
#define mn -100000000
int c[mx],d[mx];
int BinarySearch(int n)
{
    int lo = -100000000;
    int hi = 100000000;
    int ans = -1;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        int v = md;
        int flag = 0;
        for(int i=n; i>=1; i--)
        {
            v += (-c[i]);
            if(d[i]==1 && v<1900){
                flag = 1;
                break;
            }
            else if(d[i]==2 && v>=1900){
                flag = 2;
                break;
            }
        }

        if(flag==0){
            ans = md;
            lo = md + 1;
        }
        else if(flag==1){
            lo = md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        bool flag = true;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&c[i],&d[i]);
            if(d[i]==2) flag = false;
        }

        if(flag){
            printf("Infinity\n");
            continue;
        }

        int ans = BinarySearch(n);

        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}
