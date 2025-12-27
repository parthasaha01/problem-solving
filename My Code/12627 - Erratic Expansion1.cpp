#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[35];

//char a[5000][5000];
//char b[5000][5000];
//void calc(int n)
//{
//    for(int i=1; i<=(n/2); i++){
//        for(int j=1; j<=(n/2); j++){
//            b[2*i-1][2*j-1] = a[i][j];
//            b[2*i-1][2*j] = a[i][j];
//            b[2*i][2*j-1] = a[i][j];
//            b[2*i][2*j] = 'B';
//        }
//    }
//
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++){
//            a[i][j] = b[i][j];
//        }
//    }
//}
//void show(int n)
//{
//    printf("n=%d\n",n);
//    int sum = 0;
//    vector<int>vv;
//    for(int i=1; i<=n; i++){
//        int cnt = 0;
//        for(int j=1; j<=n; j++){
//            printf("%c ",a[i][j]);
//            if(a[i][j]=='R')cnt++;
//        }
//        sum+=cnt;
//        printf("\n");
//        vv.push_back(cnt);
//    }
//
//    for(int i=0; i<vv.size(); i++){
//        printf("%d ",vv[i]);
//    }
//    printf(" = %d\n\n",sum);
//
//}
//void bruteforce()
//{
//    a[1][1] = 'R';
//    for(int i=2; i<=1000; i*=2)
//    {
//        calc(i);
//        show(i);
//        getchar();
//    }
//}
ll fun(ll n,ll k,ll m)
{
    if(n==0 || k==0)return 0LL;
    ll md = (1LL<<(k-1));
    if(n<=md) return m*sum[k-1] + fun(n,k-1,m<<1LL);
    else return fun(n-md,k-1,m);
}
int main()
{
    //bruteforce();
    sum[0] = 1;
    for(int i=1; i<=32; i++)sum[i] = sum[i-1]*3;

    int tt; cin>>tt;
    for(int ks=1; ks<=tt; ks++)
    {
        ll k,l,r;
        cin>>k>>l>>r;
        ll ans = 0;
        ans += (sum[k]-fun(r,k,1LL));
        if(l>1)ans -= (sum[k]-fun(l-1,k,1LL));
        cout << "Case " << ks << ": " << ans << endl;
    }

    return 0;
}

