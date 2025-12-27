#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Tree{
    int dig[22];
}tree[4*maxn];
int lazy[4*maxn];

void PushUp(int rt)
{
    for(int i= 0; i < 22; i++)
    {
        tree[rt].dig[i] = tree[rt<<1].dig[i] + tree[rt << 1|1].dig[i];
    }
}
void PushDown(int rt, int l, int r)
{
    if(lazy[rt] == 0) return;
    lazy[rt<<1] ^= lazy[rt];
    lazy[rt<<1|1] ^= lazy[rt];
    int m = (l + r) >> 1;
    for(int i = 0; i < 22; i++)
    {
        int d = 1 << i;
        if(lazy[rt] & d)
        {
            tree[rt << 1].dig[i] = m - l + 1 - tree[rt << 1].dig[i];
            tree[rt << 1|1].dig[i] = r - m - tree[rt << 1|1].dig[i];
        }
    }
    lazy[rt] = 0;
}
void Build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if(l == r)
    {
        int a;
        cin >> a;
        for(int i = 0; i < 22; i++)
        {
            if(a & 1 << i)
                tree[rt].dig[i] = 1;
            else
                tree[rt].dig[i] = 0;
        }
        return;
    }
    int m = (l + r) >> 1;
    Build(l,m,rt*2);
    Build(m+1,r,rt*2+1);
    PushUp(rt);
}

void Update(int l, int r, int rt, int L, int R, int x)
{
    if(L <= l && r <= R)
    {
        lazy[rt] ^= x;
        for(int i = 0; i < 22; i++)
        {
            if(x & (1 << i))
            {
                tree[rt].dig[i] = r - l + 1 - tree[rt].dig[i];
            }
        }
        return ;
    }
    PushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m)
        Update(l,m,rt*2, L, R, x);
    if(m < R)
        Update(m+1,r,rt*2+1, L, R, x);
    PushUp(rt);
}
long long  Query(int l, int r, int rt, int L, int R)
{
    long long ret = 0;
    if(L <= l && r <= R)
    {
        for(int i = 0; i < 22; i++)
        {
            ret = ret + (long long)tree[rt].dig[i] * (1 << i);
        }
        return ret;
    }
    PushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m)
        ret += Query(l,m,rt*2, L, R);
    if(m < R)
        ret += Query(m+1,r,rt*2+1, L, R);
    PushUp(rt);
    return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        Build(1, n, 1);
        int m;
        cin >> m;
        while(m--)
        {
            int cmd, l, r, x;
            cin >> cmd;
            if(cmd == 1)
            {
                cin >> l >> r;
                cout << Query(1, n, 1, l, r) << endl;
            }
            else
            {
                cin >> l >> r >> x;
                Update(1, n, 1, l, r, x);
            }
        }
    }
    return 0;
}
/*
17
1000000 199999 99999 1097 678736 722866 823736 172363 163783 123 12435 263535 735355 2525 52525 263543 435442
10
1 1 13
4874027

2 2 12 19087
1 2 16
4319185

2 4 9 101823
1 3 17
4862275

2 1 17 108837
1 1 10
3935525

2 10 15 152452
1 1 1
977765

1 6 11
2390934

*/
