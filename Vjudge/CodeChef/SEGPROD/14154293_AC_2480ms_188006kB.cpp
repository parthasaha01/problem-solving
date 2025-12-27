#include<bits/stdc++.h>
using namespace std;

int tl[21][1000005];
int tr[21][1000005];

int a[1000005],b[1000005];

int main()
{
    ios_base::sync_with_stdio(0);

    int t; cin >> t;

    while (t--)
    {
        int n,p,q; cin >> n >> p >> q;

        for (int i = 0; i < n; ++i) cin >> a[i];

        int cnt = (q >> 6) + 2;
        for (int i = 0; i < cnt; ++i) cin >> b[i];

        /// Preprocess
        for (int k = 0; (1<<k)<=n ; k++)
        {
            int ones = (1<<k) - 1;

            long long tmp = 1;
            for (int i = 0; i < n; i++)
            {
                tmp *= a[i];
                tmp %= p;
                tl[k][i] = tmp;
                if ((i & ones) == ones) tmp = 1;
            }

            tmp = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                tmp *= a[i];
                tmp %= p;
                tr[k][i] = tmp;
                if ((i & ones) == 0) tmp = 1;
            }
        }

        int prev=0, l=0, r=0;

        for (int i = 0; i < q; ++i)
        {
            if ((i%64) == 0){
                l = b[(i/64)] + prev;
                r = b[(i/64) + 1] + prev;
            }
            else{
                l += prev;
                r += prev;
            }

            l %= n; r %= n;
            if (l > r) swap(l, r);

            long long ans;
            if (l == r){
                ans = a[l];
            }
            else{
                int num = 31 - __builtin_clz(l ^ r);
                ans = tl[num][r];
                ans *= tr[num][l];
            }

            ans = (ans + 1) % p;
            prev = ans;
        }

        cout << prev << "\n";
    }
    return 0;
}