#include<bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE = 320;
int a[100005],s[100005],ans[100005],cnt[1050000];
int n,k,m;
struct data{
    int l,r,i;
};
vector<data>block[320];
bool cmp(data x,data y){
    if(x.r!=y.r)return x.r<y.r;
    return x.l < y.l;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        s[i] = s[i-1]^a[i];
    }

    for(int i=1; i<=m; i++){
        int l,r; scanf("%d%d",&l,&r);
        //l--,r--;
        block[l/BLOCK_SIZE].push_back({l,r,i});
    }

    for(int i=0; i<320; i++){
        sort(block[i].begin(),block[i].end(),cmp);
    }

    int l=1,r=0,sum=0;
   // cnt[0] = 1;
    memset(cnt,0,sizeof(cnt));
    cnt[0] = 1;
    for(int i=0; i<320; i++){
        for(int j=0; j<block[i].size(); j++){
            data q = block[i][j];

            while(r<q.r){
                ++r;
                printf("2 r=%d s[r]=%d sum=%d cnt[%d]=%d\n",r,s[r],sum,s[r],cnt[s[r]]);
                cnt[s[r]]++;
                int xr = s[r]^k;
                sum += cnt[xr];

                printf("2 r=%d xr=%d s[r]=%d cnt[xr]=%d sum=%d cnt[%d]=%d\n\n",r,xr,s[r],cnt[xr],sum,s[r],cnt[s[r]]);
            }
            while(l>q.l){
                --l;
                cnt[s[l]]++;
                int xr = s[l-1]^k;
                sum += cnt[xr];

            }
            while(r>q.r){
                int xr = s[r-1]^k;
                sum -= cnt[xr];
                if(cnt[s[r]]>0)cnt[s[r]]--;
                r--;
            }
            while(l<q.l){
                printf("1 l=%d s[l]=%d sum=%d cnt[%d]=%d\n",l,s[l],sum,s[l],cnt[s[l]]);
                int xr = s[l]^k;
                sum -= cnt[xr];
                if(cnt[s[l]]>0)cnt[s[l]]--;
                l++;
            }

            ans[q.i] = sum;

            printf("q.l=%d q.r=%d q.i=%d ans=%d\n\n",q.l,q.r,q.i,ans[q.i]);
        }
    }

    for(int i=1; i<=m; i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}
