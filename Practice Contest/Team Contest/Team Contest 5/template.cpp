#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

//#include <sys/resource.h>     // for linux stack memory increase
//#define gc getchar_unlocked   // for linux fast io
//#define gc getchar            // for windows fast io

template <class T> inline T mul(T p, T e, T M)
{
    long long ret = 0;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M) ret-=M;
        if(p>=M) p-=M;
    }
    return (T)ret;
}
template<class T> inline void input(T &x)
{
    register char c = getchar();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    if(c=='-'){
        neg = 1;
        c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()){
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x = -x;
}

int  Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int  Reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
template< class T, class X > inline T   togglebit(T a, X i)
{
    T t=1;
    return (a^(t<<i));
}

/// GEOMETRY
typedef long double ld;
ld INF = 1e100;
ld EPS = 1e-12;

struct PT
{
    ld x, y;
    PT() {}
    PT(ld x, ld y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (ld c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (ld c)     const
    {
        return PT(x/c,   y/c  );
    }
    bool operator <(const PT &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

ld dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
ld dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
ld cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
ostream &operator<<(ostream &os, const PT &p)
{
    os << "(" << p.x << "," << p.y << ")";
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, ld t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
ld ComputeSignedArea(const vector<PT> &p)
{
    ld area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

ld ComputeArea(const vector<PT> &p)
{
    return fabs(ComputeSignedArea(p));
}

PT ComputeCentroid(const vector<PT> &p)
{
    PT c(0,0);
    ld scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

ld angle(PT p1, PT p2, PT p3)
{ // angle from p1->p2 to p1->p3, returns -PI to PI
    PT va = p2-p1,vb=p3-p1;
    ld x,y;
    x=dot(va,vb);
    y=cross(va,vb);
    return(atan2(y,x));
}
double DEG(double x)
{
    return (180.0*x)/(pi);
}
double RAD(double x)
{
    return (x*(double)pi)/(180.0);
}
bool colin(int i,int j,int k)
{ ///check if points in index i,j,k are colinear
    return (x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]))==0;
}


/// HASH
template <class T> inline T gethash(T h[],T power[],int l,int r)
{
    if(r<l) return (T) 0;
    return h[l]-h[r+1]*power[r-l+1];
}
const ll mod[]  = {1000000007,1000000009,1000000021,1000000033};
const ll mod[]  = {1000000097,1000000093,1000000097,1000000103};
const ll base[] = {0,1000003,1000033,1000037,1000039,1000081,1000099};
#define MOD 999995959, 999998777, 101949101, 104282401, 70139317
#define MD1 1000000007ULL, MD2 1000000009ULL, 1000000021ULL
#define BASE 10000019ULL, 10000079ULL, 10000103ULL, 1000117, 1000121
//----------------------------------------------------
