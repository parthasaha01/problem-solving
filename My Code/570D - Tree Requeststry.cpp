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
//template <typename T> LL isLeft(T a,T b,T c) {return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}
//long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
//bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
//int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
//#define good   st<=l&&ed>=r
//#define seg    int mid=(l+r)/2,lft=2*id,rgt=lft+1
//#define MX  500007
///**********************************************************//
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define SQ(n) (n*n)
#define ll long long
#define llu unsigned long long

#define pi acos(-1.0)

#define all(a) a.begin(),a.end()
#define _max(a,b,c) Max(a,Max(b,c))
#define _min(a,b,c) Min(a,Min(b,c))

#define FOR(i,a,b) for(int i=a;i<b; i++)

#define MEM(a,val) memset(a,val,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

#define tover(QLOW, QHIGH, LOW, HIGH) QLOW<=LOW && QHIGH>= HIGH
#define nover(QLOW, QHIGH, LOW, HIGH) QLOW>HIGH || QHIGH<LOW

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)
#define MOD 1000000007
#define inf INT_MAX/3
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
#define mx 500010
#define pii pair<int,int>
int in[mx], out[mx],vis[mx],dep[mx];
int tym = 1;
int LEFT, RIGHT;
int h,vv;
vi G[mx];
vi hei[mx];
vi cum[mx];
int MMAXH = 0;
void dfs(int u, int govir)
{
    vis[u] = 1;
    in[u] = tym++;
    dep[u] = govir;
    MMAXH = max(MMAXH,govir);
    hei[govir].push_back(u);
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!vis[v])
            dfs(v,govir+1);
    }
    out[u] = tym++;
}
void binleft(int lo, int hi, int val)
{
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        int cur  = in[hei[h][mid]];
        if(cur >=in[val] && cur<=out[val])
        {
            LEFT = mid;
            hi = mid-1;
        }
        else if(cur<in[val])
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
}
void binright(int lo, int hi, int val)
{
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        int cur  = in[hei[h][mid]];
        if(cur >=in[val] && cur<=out[val])
        {
            RIGHT = mid;
            lo = mid+1;
        }
        else if(cur<in[val])
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=2; i<=n; i++)
    {
        int ver;
        cin >> ver;
        G[i].pb(ver);
        G[ver].pb(i);
    }
    dfs(1,1);
    string str;
    cin >> str;
    for(int i=1; i<=MMAXH; i++)
    {
        cum[i].resize((int)hei[i].size()+1);
        cum[i][0] = 0;
        for(int j=0; j<hei[i].size(); j++)
        {
            int v = str[hei[i][j]-1] -'a';
            cum[i][j+1] = cum[i][j] ^ (1<<v);
//            cout << cum[i][j+1] << " = " << str[hei[i][j]-1] ;
        }
//        cout << endl;
    }

    while(m--)
    {
        cin >> vv >> h;
        if(dep[vv]>h || h>MMAXH)
            cout << "Yes" << endl;
        else
        {
            LEFT = -1;
            RIGHT = -1;
            binleft(0,hei[h].size()-1,vv);
            binright(0,hei[h].size()-1,vv);
//            cout << LEFT << " " << RIGHT << endl;
            if(LEFT == -1)
                cout << "Yes" << endl;
            else
            {
                int odd = 0;
                int val = cum[h][RIGHT+1] ^ cum[h][LEFT];
                odd = __builtin_popcount(val);
                if((RIGHT-LEFT+1)%2==0){
                    if(odd==0)cout << "Yes" << endl;
                    else cout << "No" << endl;
                }
                else{
                    if(odd==1)cout << "Yes" << endl;
                    else cout << "No" << endl;
                }
            }
        }
    }

    return 0;
}

