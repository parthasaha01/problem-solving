#include<bits/stdc++.h>
using namespace std;
#define i64 unsigned long long
#define pii pair<int,int>
map< pair<int,int>,int > mp;
int f[1000005];
i64 BIGMOD(i64 b,i64 p,i64 MOD)
{
    i64 res = 1%MOD, x = b%MOD;
    while(p)
    {
        if(p&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        p >>= 1LL;
    }
    return res;
}
int main()
{
    int t;scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        i64 a,b,n;
        scanf("%llu %llu %llu",&a,&b,&n);

        if(n==1){
            printf("0\n");
            continue;
        }
        if(a==0){
            printf("0\n");
            continue;
        }
        if(a==1 || b==0){
            printf("1\n");
            continue;
        }

        mp.clear();
        i64 MOD = 1;
        f[0] = 0; f[1] = 1;
        mp[make_pair(f[0],f[1])] = 1;
        int k = 2;
        while(1)
        {
            f[k] = (f[k-1]+f[k-2])%n;
            //printf("f[%d]=%d\n",k,f[k]);
            pii pp = make_pair(f[k-1],f[k]);
            if(mp.find(pp)!=mp.end()){
                MOD = k-1;
                break;
            }
            mp[pp] = 1;
            k++;
        }

        i64 ans = BIGMOD(a,b,MOD);
        //cout << a << " " << b << " " << MOD << " " << ans << endl;
        printf("%d\n",f[ans]);
    }
    return 0;
}
