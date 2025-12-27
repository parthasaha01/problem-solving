#include <bits/stdc++.h>
#define LL long long
#define PLL  pair<LL, LL>
using namespace std;

const int N = 60;
LL all = (1LL<<N) - 1;
LL a[N];
LL sum[N][N];

map<PLL, LL> mem;

LL calc(int n, int k, LL mask) {
    if (k==0) {
        if (n==0)   return all;
        else        return 0;
    }
    if (k>n)    return 0;
    if (mask == 0)  return 0;

    PLL st = {n*15153 + k, mask};
    if (mem.count(st))  return mem[st];

    LL ans = 0;
    for (int i=1; i<=n; i++) {
        LL cur = sum[i][n];
        cur = mask & cur;
        if (cur <= ans) continue;
        LL sub = calc(i-1, k-1, cur);
        ans = max(ans, sub & cur);
    }
    return mem[st] = ans;
}

LL random()
{
    LL ans = 0;
    for (int i=0; i<50; i++)
        if (rand()%2)
            ans += 1LL<<i;
    return ans;
}

int main()
{
    int n, k;
    cin>>n>>k;

    for (int i=1; i<=n; i++)
        //a[i] = random();
        cin>>a[i];

    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            for (int k=i; k<=j; k++)
                sum[i][j] += a[k];

    cout<<calc(n, k, all)<<endl;
}
