/********************************************
*                                           *
*    Solved By : Bir Bahadur Khatri(B'ru)   *
*      Be Positive,be Happy.                *
*                                           *
*********************************************/

#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define SQR(n) (n*n)
#define MP make_pair
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define LL long long int
#define S1(a) a=in<int>()
#define SL1(a) a=in<LL>()
#define PII pair<int,int>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define S2(a,b) a=in<int>(),b=in<int>()
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }

///**********************************************************//

#define MD1 1000000007ULL
#define MD2 1000000009ULL
#define MD3 1000000021ULL
#define BS1 10000019ULL
#define BS2 10000079ULL
#define BS3 10000103ULL
#define PUL pair<ULL,ULL>

///         0123456789
#define MX  200007
#define MOD 1000000007
#define INF (1<<28)
#define EPS 1e-9
/// ==========================================////

char s[2003];

int n,m,d;

LL dp[2002][2002][2][3];

LL SOlve(int pos,int md,int ch,int fl,string sp) {
    //trace4(pos,md,ch,fl);
    //cout<<s<<endl;
    if(pos==n) {
        if(fl&&(md==0)){
            cout<<sp<<endl;
            return 1;
        }
        return 0;
    }

    LL &res=dp[pos][md][ch][fl];
    //if(res!=-1) return res;


    res=0;

    int l=0,h=( s[pos]-'0' );
    int aa=h;
    if(ch) h=9;

    if(!fl) {
        res=(res+SOlve(pos+1,md,1,fl,sp))%MOD;
    }

    for(int i=l;i<=h;i++) {
        if(fl==0&&i==0) continue;
        if(fl==1) {
            if(i==d) {
                string ss = sp;
                ss += i+'0';
                res=(res+SOlve(pos+1,(md*10+i)%m,ch|(i<aa),2,ss))%MOD;
            }
        }
        else {
            if(i==d) continue;
            string ss = sp;
            ss += i+'0';
            res=(res+SOlve(pos+1,(md*10+i)%m,ch|(i<aa),1,ss))%MOD;
        }
    }
    return res;
}

int main()
{

    S2(m,d);
    scanf("%s",&s);
    n=strlen(s);
    MEM(dp,-1);
    LL ans=SOlve(0,0,0,0,"");
    int f=1;
    int md=0;
    for(int i=0;i<n;i++) {
        if(i%2) {
            if( (s[i]-'0')!=d ) {
                f=0;
                break;
            }
        }
        else {
            if( (s[i]-'0')==d ) {
                f=0;
                break;
            }
        }
        md=(md*10 +( s[i]-'0' ))%m;
    }
    if(md) f=0;
    ans=(ans-f+MOD)%MOD;

    scanf("%s",&s);

    n=strlen(s);
    MEM(dp,-1);
    LL ans1=SOlve(0,0,0,0,"");
    ans=(ans1-ans+MOD)%MOD;
    printf("%lld\n",ans);



    return 0;
}
