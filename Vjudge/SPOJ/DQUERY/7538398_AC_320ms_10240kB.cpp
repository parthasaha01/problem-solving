#include<bits/stdc++.h>
using namespace std;

int a[30004], cnt[1000006], ans[200005];
int block,answer;

struct info{
    int l,r,id;
}query[200005];

bool srt(info x, info y)
{
    if(x.l/block == y.l/block) return x.r<y.r;
    return x.l < y.l;
}
void consider(int p)
{
    cnt[a[p]]++;
    if(cnt[a[p]] == 1) answer++;
}
void avoid(int p)
{
    cnt[a[p]]--;
    if(cnt[a[p]] == 0) answer--;
}

int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int q; scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&query[i].l,&query[i].r);
        query[i].l--;
        query[i].r--;
        query[i].id = i;
        ans[i] = 0;
    }

    block = sqrt(n);
    sort(query,query+q,srt);

    int cl=0, cr=0;
    answer = 0;

    for(int i=0; i<q; i++)
    {
        while(cl<query[i].l){
            avoid(cl);
            cl++;
        }
        while(cl>query[i].l){
            cl--;
            consider(cl);
        }
        while(cr<=query[i].r){
            consider(cr);
            cr++;
        }
        while(cr>query[i].r+1){
            cr--;
            avoid(cr);
        }

        ans[query[i].id] = answer;
    }

    for(int i=0;i<q;i++) printf("%d\n",ans[i]);

    return 0;
}
