#include <cstdio>
#include <cstring>
#define Null b
#define R register
int n, q;
struct Data
{
    int sum;
    char vis;
    Data *lson, *rson;
} b[15000010], *root = Null;
int tot;
#define Newnode() (b[++tot] = (Data){0, 0, Null, Null})
void Pushdown(R Data *node, R int begin, R int end)
{
    if(node->vis == 0) return ;
    R int mid = begin + end >> 1;
    if(node->lson == Null) Newnode(), node->lson = b + tot;
    if(node->rson == Null) Newnode(), node->rson = b + tot;
    if(node->vis == 1)
    {
        node->lson->vis = node->rson->vis = 1;
        node->lson->sum = mid - begin + 1, node->rson->sum = end - mid;
    }
    if(node->vis == 2)
    {
        node->lson->vis = 2, node->lson->sum = 0;
        node->rson->vis = 2, node->rson->sum = 0;
    }
    node->vis = 0;
}
void Modify1(R Data *&node, R int begin, R int end, R int l, R int r)
{
    if(node == Null)
    {
        b[++tot] = (Data) {0, 0, Null, Null}, node = b + tot;
    }
    if(node->sum == end - begin + 1) return ;
    if(l <= begin && end <= r)
    {
        node->sum = end - begin + 1;
        node->vis = 1;
        return ;
    }
    Pushdown(node, begin, end);
    R int mid = begin + end >> 1;
    if(l <= mid) Modify1(node->lson, begin, mid, l, r);
    if(r > mid) Modify1(node->rson, mid + 1, end, l, r);
    node->sum = node->lson->sum + node->rson->sum;
}
void Modify2(R Data *&node, R int begin, R int end, R int l, R int r)
{
    if(node == Null || node->sum == 0) return ;
    if(l <= begin && end <= r)
    {
        node->sum = 0;
        node->vis = 2;
        return ;
    }
    Pushdown(node, begin, end);
    R int mid = begin + end >> 1;
    if(l <= mid) Modify2(node->lson, begin, mid, l, r);
    if(r > mid) Modify2(node->rson, mid + 1, end, l, r);
    node->sum = node->lson->sum + node->rson->sum;
}
int main()
{
    b[0] = (Data)
    {
        0, 0, Null, Null
    };
    scanf("%d %d", &n, &q);
    while(q--)
    {
        R int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        if(k == 1) Modify1(root, 1, n, l, r);
        else Modify2(root, 1, n, l, r);
        printf("%d\n", n - root->sum);
    }
    return 0;
}
