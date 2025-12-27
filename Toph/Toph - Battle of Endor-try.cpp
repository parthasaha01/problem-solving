#include <bits/stdc++.h>
using namespace std;
int preve[100015], nxte[100015], prv[100015], nxt[100015], block[1010];
int cur_ans, cl, cr, mx;
int Pair[100015], cnt[100015], strong[100015];
int ans[100015];
int bsize; //block size, sqrt of n
int n,k,a[100015];
struct query{
    int l, r, id;
} qr[100015];
bool mo_comp(query l, query r){
    int block_l = l.l/bsize;
    int block_r = r.l/bsize;
    if(block_l != block_r)
        return block_l < block_r;
    return l.r < r.r;
}

void add(int i){
    if (Pair[a[i]] > 0){    Q
        block[cnt[a[i]]/100]--;
        strong[cnt[a[i]]]--;
    }

    if(i==cr){
        if (prv[i] >= cl && i - prv[i] <= k){
            Pair[a[i]]++;
        }
    }else {
        if (nxt[i] <= cr && nxt[i] - i <= k){
            Pair[a[i]]++;
        }
    }

    cnt[a[i]]++;

    if (Pair[a[i]]>0){
        block[cnt[a[i]]/100]++;
        strong[cnt[a[i]]]++;
    }
}

void rem(int i){
    if (Pair[a[i]]>0){
        block[cnt[a[i]]/100]--;
        strong[cnt[a[i]]]--;
    }

    if (i == cr){
        if (prv[i] >= cl && i - prv[i] <= k){
            Pair[a[i]]--;
        }
    }else {
        if (nxt[i] <= cr && nxt[i] - i <= k){
            Pair[a[i]]--;
        }
    }

    cnt[a[i]]--;

    if (Pair[a[i]]>0){
        block[cnt[a[i]]/100]++;
        strong[cnt[a[i]]]++;
    }
}
int get_result(){
    for (int i = 101; i >= 0; i--){
        if (block[i] > 0){
            for (int j = (i+1)*100-1; j >= i*100; j--){
                if (strong[j]>0) return strong[j];
            }
        }
    }
    return 0;
}
int main (){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

        memset(preve, 0, sizeof(preve));
        for (int i = 1; i <= n; i++){
            prv[i] = preve[a[i]];
            preve[a[i]] = i;
        }

        for (int i = 0; i <= 10010; i++) nxte[i] = n+2;
        for (int i = n; i >= 1; i--){
            nxt[i] = nxte[a[i]];
            nxte[a[i]] = i;
        }

        int q; scanf("%d",&q);
        for (int i = 1; i <= q; i++){
            int l,r; scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            qr[i].l = l;
            qr[i].r = r;
            qr[i].id = i;
        }

        bsize = sqrt((double) n);
        sort(qr + 1, qr + q + 1, mo_comp);

        memset(Pair, 0, sizeof(Pair));
        memset(cnt, 0, sizeof(cnt));
        memset(block, 0, sizeof(block));
        memset(strong, 0, sizeof(strong));

        cl = cr = 1;
        cur_ans = 0;
        add(1);
        for (int i = 1; i <= q; i++){
            while (cr < qr[i].r){
                cr++;
                add(cr);
            }
            while(cr > qr[i].r){
                rem(cr);
                cr--;
            }
            while (cl < qr[i].l){
                rem(cl);
                cl++;
            }
            while(cl > qr[i].l){
                cl--;
                add(cl);
            }

            ans[qr[i].id] = get_result();
        }

        for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
