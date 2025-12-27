#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
ll a[mx+5],sx[mx+5];
string ss[mx+5];
struct node{
    bool endmark;
    int dx;
    node *next[2];
    node(){
        endmark = false;
        dx = 0;
        next[0] = next[1] = NULL;
    }
}*root;
string DecToBin(int n,int msz)
{
    string tm;
    while(n!=0){
        tm += (n&1)+'0';
        n = n>>1;
    }
    while(tm.size()<msz) tm+='0';

    reverse(tm.begin(),tm.end());
    return tm;
}
void Insert(string s,int x)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = true;
    cur->dx = x;
}
int query(string s)
{
    node *cur = root;

    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        int nx = 1-id;
        if(cur->next[nx]==NULL)cur = cur->next[id];
        else cur = cur->next[nx];
    }

    return cur->dx;
}
void del(node *cur)
{
    for(int i=0; i<2; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        root = new node();

        int n; scanf("%d",&n);
        ll maxx = -1;
        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
            maxx = max(maxx,a[i]);
        }

        int msz;
        if(maxx==0)msz=1;
        else msz = floor(log2(maxx))+1;

        sx[0]=0;
        ll ans = maxx;
        for(int i=1; i<=n; i++){
            sx[i] = sx[i-1]^a[i];
            ans = max(ans,sx[i]);
            ss[i] = DecToBin(sx[i],msz);
        }

        for(int i=1; i<=n; i++){
            Insert(ss[i],i);
            int tx = query(ss[i]);
            ll xr = sx[i]^sx[tx];
            ans = max(ans,xr);
        }

        printf("%lld\n",ans);

        del(root);
    }
    return 0;
}
