#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int x[mx],m[mx],cnt[mx],sum[mx];
int main()
{
    int n;

    while(scanf("%d",&n)==1)
    {

        memset(cnt,0,sizeof(cnt));
        int maxx=0;

        for(int i=0; i<n; i++)
        {
            scanf("%d",&x[i]);
            cnt[x[i]]++;
        }

        for(int i=1; i<mx; i++)
        {
            cnt[i]+=cnt[i-1];
            //sum[i]=sum[i-1]+cnt[i];
        }

        int q;
        scanf("%d",&q);

        for(int i=0; i<q; i++)
        {
            int res;
            scanf("%d",&m[i]);

            if(m[i]>=100005){
                res=cnt[mx-2];
            }
            else{
                res=cnt[m[i]];
            }
            printf("%d\n",res);
        }
    }

    return 0;

}
