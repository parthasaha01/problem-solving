#include <iostream>
#include <cstdio>
#include <map>
#define F first
#define S second
using namespace std;

int n, m, l, r, k, st, en, num, ans;
map<int, int> v;
int main()
{
    map<int, int>::iterator it;
    cin >> n >> m;
    ans = n;
    while (m--)
    {
        scanf ("%d %d %d", &l, &r, &k);
        it = v.lower_bound(l);
        while (it != v.end())
        {
            st = it->S;
            en = it->F;
            num = min(en, r) - max(st, l) + 1;
            if (num <= 0) break;
            v.erase(it++);
            ans += num;
            if (st < l) v[l - 1]=st;
            if (en > r) v[en] = r + 1;
        }
        if (k == 1)
        {
            v[r] = l;
            ans -= r - l + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
