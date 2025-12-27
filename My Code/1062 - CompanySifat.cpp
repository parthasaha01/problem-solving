///   |----------------------------|
///   | BISMILLAHIR RAHMANIR RAHIM |
///   |----------------------------|

///       _______  __   ________   ___   .___________.
///      /       ||  | |   ____|  /   \  |           |
///     |   (----'|  | |  |__    /  ^  \ `---|  |----`
///      \   \    |  | |   __|  /  /_\  \    |  |
///  |----)   |   |  | |  |    /  _____  \   |  |
///  |_______/    |__| |__|   /__/     \__\  |__|
///


//#define BitCnt(a) __builtin_popcountll(a)
//template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
//template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
//template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
//template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
//long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
//bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
//long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
//template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
//bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//#define good   st<=l&&ed>=r
//#define seg    int mid=(l+r)/2,lft=2*id,rgt=lft+1
//#define MX  500007
///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define   ff   first
#define   ss   second
#define   pb   push_back
#define   mp   make_pair

#define   SQ(n)         (n*n)
#define   ll            long long
#define   llu           unsigned long long

#define   pi            acos(-1.0)

#define   all(a)        a.begin(),a.end()
#define   _max(a,b,c)   Max(a,Max(b,c))
#define   _min(a,b,c)   Min(a,Min(b,c))

#define   FOR(i,a,b)    for(int i=a;i<b; i++)

#define   MEM(a,val)    memset(a,val,sizeof(a))

#define   sf(a)         scanf("%d",&a)
#define   sf2(a,b)      scanf("%d%d",&a,&b)
#define   sf3(a,b,c)    scanf("%d%d%d",&a,&b,&c)
#define   sf4(a,b,c,d)  scanf("%d%d%d%d",&a,&b,&c,&d)

#define   sfl(a)        scanf("%lld",&a)
#define   sfl2(a,b)     scanf("%lld%lld",&a,&b)
#define   sfl3(a,b,c)   scanf("%lld%lld%lld",&a,&b,&c)
#define   sfl4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

#define   pnl()         printf("\n")

#define   pfc(a)        printf("Case %d: ",a)
#define   pf(a)         printf("%d",a)
#define   pf2(a,b)      printf("%d %d",a,b)
#define   pf3(a,b,c)    printf("%d %d %d",a,b,c)
#define   pf4(a,b,c,d)  printf("%d %d %d %d",a,b,c,d)

#define   pflc(a)       printf("Case %lld: ",a)
#define   pfl(a)        printf("%lld",a)
#define   pfl2(a,b)     printf("%lld %lld",a,b)
#define   pfl3(a,b,c)   printf("%lld %lld %lld",a,b,c)
#define   pfl4(a,b,c,d) printf("%lld %lld %lld %lld",a,b,c,d)

#define   tover(QLOW, QHIGH, LOW, HIGH)   QLOW<=LOW && QHIGH>= HIGH /// QLOW,QHIGH = Jei Query Ber korbo
#define   nover(QLOW, QHIGH, LOW, HIGH)   QLOW>HIGH || QHIGH<LOW

#define   bitCheck(a,k)  ((bool)(a&(1<<(k))))
#define   bitOff(a,k)    (a&(~(1<<(k))))
#define   bitOn(a,k)     (a|(1<<(k)))
#define   bitFlip(a,k)   (a^(1<<(k)))

#define   POPCOUNT       __builtin_popcount
#define   POPCOUNTLL     __builtin_popcount
#define   RIGHTMOST      __builtin_ctzll
#define   LEFTMOST(x)    (63-__builtin_clzll((x)))

#define   pii      pair<int,int>
#define   pll      pair<ll,ll>
#define   vi       vector<int>
#define   FI       freopen("in.txt", "r", stdin)
#define   FO       freopen("out.txt", "w", stdout)
#define   MOD      1000000007
#define   inf      INT_MAX/3

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

#define   fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mx 100010
vector<int>G[mx];
int T[mx], L[mx], P[mx][25],n;
int dis[mx];
struct st
{
    int ver;
    int val;
} tree[mx*4],tree_mn[mx*4];

int tym = 0;
void dfs(int src, int par, int dep)
{
    T[src] = par;
    L[src] = dep;
    dis[src]=++tym;
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i];
        if(v!=par)
            dfs(v, src, dep+1);
    }
}
void lca_init()
{
    memset(P,-1,sizeof(P));
    for(int i=1; i<=n; i++)
        P[i][0] = T[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(P[i][j-1]!=-1)
            {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}
int lca_query(int u, int v)
{
    if(u==n+1 || u == -1)
        return v;
    if(v==n+1 || v == -1)
        return u;

    if(u==v)
        return u;
    if(L[u]<L[v])
        swap(u,v);
    int log = 20;
    for(int i=log; i>=0 ; i--)
    {
        if(P[u][i]!=-1 && (L[u]-(1<<i))>=L[v])
            u = P[u][i];
    }
    if(u==v)
        return u;
    for(int i=log; i>=0; i--)
    {
        if(P[u][i] != -1 && P[v][i] != -1 && P[u][i]!=P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].ver = b;
        tree[node].val = dis[b];
        tree_mn[node] = tree[node];
        return;
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    build(L,b,mid);
    build(R,mid+1,e);

    if(tree[L].val>tree[R].val)
    {
        tree[node] = tree[L];
    }
    else
    {
        tree[node] = tree[R];
    }

    if(tree_mn[L].val>tree_mn[R].val)
    {
        tree_mn[node] = tree_mn[R];
    }
    else
    {
        tree_mn[node] = tree_mn[L];
    }
}

st query(int node, int b, int e, int i, int j)
{
    if(nover(i,j,b,e))
    {
        st ret;
        ret.val = -inf;
        ret.ver = 0;
        return ret;
    }
    if(tover(i,j,b,e))
    {
        return tree[node];
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    st ret1 = query(L,b,mid,i,j);
    st ret2 = query(R,mid+1,e,i,j);

    if(ret1.val>ret2.val)
        return ret1;
    return ret2;
}

st query_min(int node, int b, int e, int i, int j)
{
    if(nover(i,j,b,e))
    {
        st ret;
        ret.val = inf;
        ret.ver = 0;
        return ret;
    }
    if(tover(i,j,b,e))
    {
        return tree_mn[node];
    }
    int mid = (b+e)/2;
    int L = node*2;
    int R = L+1;

    st ret1 = query_min(L,b,mid,i,j);
    st ret2 = query_min(R,mid+1,e,i,j);

    if(ret1.val>ret2.val)
        return ret2;
    return ret1;
}
int range_lca(int u, int v)
{
    if(u==v) return u;
    int val1 = query(1,1,n,u,v).ver;
    int val2 = query_min(1,1,n,u,v).ver;
//        cout <<"val1 = " << val1 << endl;
//        cout <<"val2 = " << val2 << endl;
    int lca = lca_query(val1,val2);
//        cout << lca << endl;
    return lca;
}
int hisab(int u,int v, int v1)
{
    int len = v-u+1;
    int rs1=-1,rs2=-1;
    if(v1==u || v1==v)
    {
        if(v1==u)
        {
            if(len>2)
            {
                rs1 = range_lca(u+1,v);
            }
            else
                rs1 = v;
        }
        else if(v1==v)
        {
            if(len>2)
            {
                rs1 = range_lca(u,v-1);
            }
            else
                rs1 = u;
        }
    }
    else
    {
        rs1 = lca_query(range_lca(u,v1-1),range_lca(v1+1,v));
    }
    return rs1;
}
int main()
{
    sf(n);
    int q;
    sf(q);
    for(int i=2; i<=n; i++)
    {
        int u, v = i;
        sf(u);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1,0);
    lca_init();
    build(1,1,n);
    while(q--)
    {
        int u,v;
        sf2(u,v);
        int len = v-u+1;
        int v1 = query(1,1,n,u,v).ver;
        int v2 = query_min(1,1,n,u,v).ver;

        //cout<<v2<<" "<<v1<<endl;

        /// for v1
        int rs1 = hisab(u,v,v1);
        int rs2 = hisab(u,v,v2);


        if(L[rs1]>L[rs2])
        {
            pf2(v1,L[rs1]);
            pnl();
        }
        else
        {
            pf2(v2,L[rs2]);
            pnl();
        }
    }

}
