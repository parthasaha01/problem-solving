#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100005;
int a[MAXN], cum[MAXN];

struct Node{
    int cnt;
    Node *next[2];
    Node(){
        cnt = 0;
        next[0] = next[1] = NULL;
    }
}*root;

string DecToBin(int n,int msz){
    string s;
    while(n!=0){
        s += (n&1) + '0';
        n >>= 1;
    }
    while((int)s.size()<msz) s += '0';
    reverse(s.begin(), s.end());
    return s;
}

void Insert(string s){
    Node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i] - '0';
        if(cur->next[id] == NULL) cur->next[id] = new Node();
        cur = cur->next[id];
        cur->cnt++;
    }
}

int query(string s, string k){
    Node *cur = root;
    int cnt = 0;
    //cout << s << " " << k << endl;
    for(int i=0; i<s.size(); i++){
        int ids = s[i] - '0';
        int idk = k[i] - '0';

        //printf("i = %d ids=%d idk=%d cnt=%d\n",i, ids,idk,cnt);

        if(ids==0 && idk==0){
            if(cur->next[0]==NULL)return cnt;
            cur = cur->next[0];
        }
        else if(ids==0 && idk==1){
            if(cur->next[0]!=NULL) cnt += cur->next[0]->cnt;
            if(cur->next[1]==NULL)return cnt;
            cur = cur->next[1];
        }
        else if(ids==1 && idk==0){
            if(cur->next[1]==NULL)return cnt;
            cur = cur->next[1];
        }
        else{
            if(cur->next[1]!=NULL) cnt += cur->next[1]->cnt;
            if(cur->next[0]==NULL)return cnt;
            cur = cur->next[0];
        }
    }

    return cnt;
}

void del(Node *cur){
    for(int i=0; i<2; i++){
        if(cur->next[i]) del(cur->next[i]);
    }
    delete(cur);
}

int main() {
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        int n,k; scanf("%d%d",&n,&k);
        int maxx = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            maxx = max(maxx, a[i]);
        }

        int msz;
        if(maxx == 0) msz = 1;
        else msz = floor(log2(maxx)) + 1;

        int msk =  floor(log2(k)) + 1;

        msz = max(msz,msk);

        string s, kk;
        s  = DecToBin(0, msz);
        kk = DecToBin(k, msz);

        root = new Node();
        Insert(s);

        ll ans = 0;
        int p = 0;
        for(int i=1; i<=n; i++){
            int q = p^a[i];
            s = DecToBin(q, msz);

            ans += query(s, kk);
            Insert(s);
            p = q;
            //printf("i=%d ans = %lld\n",i,ans);
        }

        printf("%lld\n",ans);

        del(root);
    }

    return 0;
}
