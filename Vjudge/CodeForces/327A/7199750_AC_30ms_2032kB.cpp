//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]= {0,0,1,-1,-1,-1,1,1};
int dy[]= {1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos)
{
    return n |((T)1<<pos);
}
template < class T> inline T bitoff(T n,T pos)
{
    return n & ~((T)1<<pos);
}
template < class T> inline T on(T n,T pos)
{
    return (bool)(n & ((T)1<<pos));
}
template < class T> inline T gcd(T a, T b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}
inline int nxt()
{
    int aaa;
    scanf("%d",&aaa);
    return aaa;
}
inline ll lxt()
{
    ll aaa;
    scanf("%I64d",&aaa);
    return aaa;
}
template <class T> inline T bigmod(T p,T e,T m)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (T)ret;
}
#define sayed
#ifdef sayed
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///******************************************START******************************************


int main()
{
    int n;
    while(cin>>n)
    {
        int ar[109];
        for(int i=0; i<n; i++ ) cin>>ar[i];
        int mx=-1,x=0,y=0;

        for( int i=0; i<n; i++ )
        {
            for( int j=i; j<n; j++ )
            {
                int cnt=0;
                //cout<<"102 "<<i<<" "<<j<<endl;
                //if( ar[i] == 0 && ar[j] == 0 )
                    for( int k=0; k<n; k++ )
                    {

                        if(k>=i&&k<=j)
                        {
                            if(ar[k]==0){
                                cnt++;
                            }
                        }
                        else
                        {
                            if(ar[k]==1){
                                cnt++;
                            }
                        }
                    }

                    if( mx < cnt )
                    {
                        mx=cnt;
                    }
            }
        }

        cout<<mx<<endl;
    }
    return 0;
}

