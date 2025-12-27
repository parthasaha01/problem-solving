#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
#define mp make_pair
#define pb push_back
const int BLOCK_SIZE = 320;
int cnt[mx],a[mx],ans[mx],sum;
vector< pair<int, pair<int,int> > > qr[BLOCK_SIZE];
void Add(int x)
{
    if(cnt[a[x]]==a[x])sum--;
    cnt[a[x]]++;
    if(cnt[a[x]]==a[x])sum++;
}
void Remove(int x)
{
    if(cnt[a[x]]==a[x])sum--;
    cnt[a[x]]--;
    if(cnt[a[x]]==a[x])sum++;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(a[i]>n)a[i]=n+1;
    }

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
        printf("%d\n",ans[i]);
    }

    return 0;
}


