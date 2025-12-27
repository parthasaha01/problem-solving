#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200005
#define mp make_pair
#define pb push_back
const int BLOCK_SIZE = 450;
int cnt[1000005],a[mx];
ll ans[mx],sum;
vector< pair<int, pair<int,int> > > qr[BLOCK_SIZE];
void Add(int x)
{
    sum += (cnt[a[x]]+cnt[a[x]]+1LL)*a[x];
    cnt[a[x]]++;
}
void Remove(int x)
{
    sum -= (cnt[a[x]]+cnt[a[x]]-1LL)*a[x];
    cnt[a[x]]--;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    int block = sqrt(n);

    for(int i=0; i<q; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        int block = x/BLOCK_SIZE;
        qr[block].pb(mp(y,mp(x,i)));
    }

    for(int i=0; i<BLOCK_SIZE; i++){
        sort(qr[i].begin(),qr[i].end());
    }

    sum= 0;
    int x=1,y=0;
    for(int k=0; k<BLOCK_SIZE; k++)
    {
        for(int i=0; i<qr[k].size(); i++)
        {
            int left = (qr[k][i].second).first;
            int right = qr[k][i].first;
            int idx = (qr[k][i].second).second;

            while(x<left) Remove(x++);
            while(x>left) Add(--x);
            while(y<right) Add(++y);
            while(y>right) Remove(y--);

            ans[idx] = sum;
        }
    }

    for(int i=0; i<q; i++){
        printf("%lld\n",ans[i]);
    }

    return 0;
}

