#include <cstdio>
#include <algorithm>
using namespace std;

int a[105];

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        int x = n/k;
        int ans = 0;

        for (int i = 1; i <= k; i++)
        {
            int m = 0;
            for (int j = i; j <= n; j+= k)
            {
                int cnt = 0;
                for (int l = j; l <= n; l += k)
                {
                    if (a[j] == a[l])
                        cnt++;
                    if (cnt > m)
                        m = cnt;
                }
            }
            ans += (x-m);
        }
        printf("%d\n", ans);
    }
    return 0;
}
