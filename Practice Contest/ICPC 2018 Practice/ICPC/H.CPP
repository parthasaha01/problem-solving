#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL;
char s[100005];
ll n, sum[100005][2], two[100005], ans;
void precalc()
{
    sum[0][0] = 1;
    sum[0][1] = 1;
    sum[1][0] = 2;
    sum[1][1] = 1;
    for(int i=2; i<=100001; i++){
        sum[i][0] = sum[i-1][1]*2;

        sum[i][0] %= MOD;
        sum[i][0] += MOD;
        sum[i][0] %= MOD;

        if(i%2==0){
            sum[i][1] = sum[i][0]+1;
        }
        else{
            sum[i][1] = sum[i][0]-1;
        }

        sum[i][1]%=MOD;
        sum[i][1] += MOD;
        sum[i][1]%=MOD;
    }
    two[0] = 1;
    for(int i=1; i<=100001; i++){
        two[i] = two[i-1]*2LL;
        two[i] %= MOD;
    }

//    for(int i=1; i<=10; i++){
//        printf("%d = %lld %lld\n",i, sum[i][0], sum[i][1]);
//    }
}
ll solve()
{
    ans = 1;
    n = strlen(s);
    int www = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='W')www++;
    }

    if(www==0)return ans;
    if(www==n){
        ans = 3*two[n-1];
        ans %= MOD;
        return ans;
    }


    int st=-1, ed=n;
    int cntb=0, cnte=0;
    for(int i=0; i<n; i++){
        st++;
        if(s[i]!='W')break;
        cntb++;
    }

    for(int i=n-1; i>=0; i--){
        ed--;
        if(s[i]!='W')break;
        cnte++;
    }
    char prev = s[st];
    int cnt = 0;
    //printf("st=%d ed=%d\n",st,ed);
    for(int i=st; i<=ed; i++){
        if(s[i]=='W'){
            cnt++;
        }
        else{
            if(prev==s[i]){
                //cout << prev << " " << s[i] << " " << cnt << endl;
                ans *= sum[cnt][0];
                ans %= MOD;
            }
            else{
                ans *= sum[cnt][1];
                ans %= MOD;
            }
            cnt = 0;
            prev = s[i];
        }
    }

    ans *= two[cntb];
    ans %= MOD;

    ans *= two[cnte];
    ans %= MOD;

    return ans;
}
int main()
{
    precalc();
    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++){
        scanf("%s",&s);
        ll ans = solve();
        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
