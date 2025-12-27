#include <bits/stdc++.h>

using namespace std;

#define mx 100005
typedef vector <int> VI;

int n, q;
int par[mx];
VI tmp[mx];
bitset <mx> mark;

int fnd(int u) {
    if (par[u] == u) return u;
    return par[u] = fnd(par[u]);
}

int main() {
//    freopen("../templates/in", "r", stdin);
    int tc; scanf("%d", &tc);
    int t = 0;
    while (tc--) {
        mark = 0;
        scanf("%d %d",&n, &q);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            tmp[i].clear();
        }

        printf("Case %d:\n", ++t);
        while (q--) {
            int c; scanf("%d", &c);
            if (c == 0) {
                int u, v; scanf("%d %d", &u, &v);
                int pu = fnd(u);
                int pv = fnd(v);
                if (pu == pv) continue;
                if (tmp[pu].size() > tmp[pv].size()) {
                    swap(pu, pv);
                }

                for (auto x : tmp[pu]) tmp[pv].push_back(x);
                par[pu] = pv;
                mark[pv] = 1;
            } else if (c == 1) {
                int u, T;
                scanf("%d %d", &u, &T);
                int pu = fnd(u);
                tmp[pu].push_back(T);
                mark[pu] = 1;
            } else {
                int u, l, r;
                scanf("%d %d %d", &u, &l, &r);
                int pu = fnd(u);
                int ans = 0;
                if (mark[pu]) {
                    sort(tmp[pu].begin(), tmp[pu].end());
                    mark[pu] = 0;
                }

                auto lt = lower_bound(tmp[pu].begin(), tmp[pu].end(), l);
                auto rt = upper_bound(tmp[pu].begin(), tmp[pu].end(), r);

                if (rt > lt) ans = rt - lt;
                printf("%d\n", ans);
            }
        }
    }
}
