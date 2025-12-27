#include<bits/stdc++.h>
using namespace std;

const int N = 10000+7;
const int RT = 100;
int a[N], l[N], r[N], last[N];
multiset<int> dis[N];
int ans[N*10], cnt[N];
int n, k;
map<int, int> fr;

void add(int idx, int d) {
    int x = a[idx];
    cnt[x]++;

    if (dis[x].size() && *dis[x].begin()<=k) {
        int sz = dis[x].size();
        fr[sz]--;
        if (fr[sz] == 0)    fr.erase(sz);
    }

    if (cnt[x] >= 2)    dis[x].insert(d);
    if (dis[x].size() && *dis[x].begin() <= k)
        fr[dis[x].size()]++;
}

void erase(int idx, int d) {
    int x = a[idx];
    cnt[x]--;

    if (dis[x].size() && *dis[x].begin()<=k) {
        int sz = dis[x].size();
        fr[sz]--;
        if (fr[sz] == 0)    fr.erase(sz);
    }

    if (cnt[x] >= 1) {
        auto it = dis[x].find(d);
        assert(it != dis[x].end());
        dis[x].erase(it);
    }
    if (dis[x].size() && *dis[x].begin() <= k)
        fr[dis[x].size()]++;
}

struct query {
    int l, r, id;
    bool operator < (query q) {
        return (l/RT != q.l/RT) ? (l/RT < q.l/RT) : (r<q.r);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--) {
        cin>>n>>k;

        memset(cnt, 0, sizeof cnt);
        for (int i=1; i<=n; i++)    dis[i].clear();
        for (int i=1; i<=n; i++)    cin>>a[i];
        fr.clear();

        memset(last, 0, sizeof last);
        for (int i=1; i<=n; i++)
            l[i] = i - last[a[i]],
            last[a[i]] = i;

        memset(last, 0, sizeof last);
        for (int i=n; i>0; i--)
            r[i] = last[a[i]] - i,
            last[a[i]] = i;

        int q;
        cin>>q;

        vector<query> queries;
        for (int i=0; i<q; i++) {
            int l, r;
            cin>>l>>r;
            queries.push_back({l, r, i});
        }

        sort(queries.begin(), queries.end());
        int cl=1, cr=0;

        for (query q: queries) {
            while (cr<q.r) ++cr, add(cr, l[cr]);
            while (cl>q.l) --cl, add(cl, r[cl]);
            while (cr>q.r) erase(cr, l[cr]), cr--;
            while (cl<q.l) erase(cl, r[cl]), cl++;
            ans[q.id] = fr.size() ? fr.rbegin()->second: 0;
        }

        for (int i=0; i<q; i++) cout<<ans[i]<<"\n";
    }
}
