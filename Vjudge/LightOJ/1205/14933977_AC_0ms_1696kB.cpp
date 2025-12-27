#include <bits/stdc++.h>
using namespace std;
 
/*------- Constants---- */
 
#define Long                    long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define INF                     1<<29
#define EPS                     1e-9
#define Fr                      first
#define Sc                      second
#define Sz                      size()
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(n)                   int n;si(n)
#define Dii(a,b)                int a,b;si(a);si(b)
#define Diii(a,b,c)             int a,b,c;si(a);si(b);si(c)
#define Si(n)                   si(n)
#define Sii(a,b)                si(a);si(b)
#define Siii(a,b,c)             si(a);si(b);si(c)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
typedef vector<Long> vl;
/*------ template functions ------ */
#ifndef getchar_unlocked
#define getchar_unlocked getchar
#endif
template<class T> inline void si(T &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 | c>57) && c != '-');c = gc());
      if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
Long bigmod(Long p,Long e,Long M){Long ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return ret;}
Long gcd(Long a,Long b){if(b==0)return a;return gcd(b,a%b);}
Long modinverse(Long a,Long M){return bigmod(a,M-2,M);}
void io(){freopen("/Users/MyMac/Desktop/in.txt","r",stdin);}
 
/*************************** END OF TEMPLATE ****************************/
const int N = 1001;
int ar[20];
Long Memo[20][2][20];
Long var;
bool check(int index,int len)
{
      int id = 0;
      Long d = var;
      int oo[20];
      for( ; d ; id ++, d/=10) oo[id] =  d%10;
      for(int i= id-1; i> index; i-- ){
            d= 10*d + oo[i];
      }
      for(int i = index + ((len%2)? 2 : 1); i < len ;i ++) {
            d = d*10+oo[i];
      }
      if(d <= var) return 1;
      return 0;
}
Long F(int ind, bool flag , int len)
{
      if(ind == (len)/2 - 1){
            if(flag && len) return check(ind,len);
            return 1;
      }
      if(!flag && Memo[ind][flag][len] !=-1 ) return Memo[ind][flag][len];
       
      Long res= 0,Lim = flag ? ar[ind] : 9;
      for(int j= 0;j <= Lim ; j ++ ) {
            res += F(ind-1, flag && (j==Lim) , j ? (len==0 ? ind +1 : len ): len);
      }
      if(flag) return res;
      return Memo[ind][flag][len] = res;
}
 
Long Solve(Long a)
{
      var = a;
      int ind;
      for(ind = 0; a; ind ++, a/=10) ar[ind]= a%10;
      ms(Memo,-1);
      return F(ind-1,true,0);
}
int main()
{
      Di(t);
      int cs = 0;
      while(t--) {
            Long a,b;
            Sii(a,b);
            if(a>b) swap(a,b);
            printf("Case %d: %lld\n", ++cs, Solve(b) - Solve(a-1));
      }
      return 0;
}