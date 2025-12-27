#include<bits/stdc++.h>
using namespace std;
#define mx 200005
string tt,ss;
int a[mx],id[mx],n,sn;
int binarySearch()
{
    int lo = 1;
    int hi = n;
    int ans = 0;
    while(lo<=hi)
    {
        int md = (lo+hi)/2;
        bool flag = false;
        int k=0;
        for(int i=0; i<n; i++){
            if(id[i]>md && tt[i]==ss[k]){
                k++;
                if(k==sn){
                    flag = true;
                    break;
                }
            }
        }

        if(flag){
            ans = md;
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
    while(cin>>tt>>ss)
    {
        n  = tt.size();
        sn = ss.size();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            a[i]--;
            id[a[i]] = i;
        }

        int ans = binarySearch();

        printf("%d\n",ans);
    }

    return 0;
}
