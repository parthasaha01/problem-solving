#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1231;
double inf = 1000000000000000.0;
int vis[10050];
vector<ll>pr,lob,hor;
int a[1250][2];
void sieve()
{
    pr.push_back(2);
    for(ll i=3; i<=10050; i+=2){
        if(vis[i]==0){
            pr.push_back(i);
            for(ll j=i*i; j<=10050; j+=i+i){
                vis[j]=1;
            }
        }
    }
    //cout << pr.size() << endl;
}
int factorial(ll n,ll p)
{
    int cnt = 0;
    for(ll i=p; n/i>=1; i=i*p) cnt += (n/i);
    return cnt;
}
double solve(ll p,ll q,ll r,ll s)
{
    memset(a,0,sizeof(a));

    for(int i=0; i<MX; i++){
        a[i][0] += factorial(p,pr[i]);
        a[i][0] += factorial(s,pr[i]);
        a[i][0] += factorial(r-s,pr[i]);

        a[i][1] += factorial(q,pr[i]);
        a[i][1] += factorial(r,pr[i]);
        a[i][1] += factorial(p-q,pr[i]);
    }

    for(int i=0; i<MX; i++){
        if(a[i][0]>=a[i][1]){
            a[i][0] -= a[i][1];
            a[i][1] = 0;
        }
        else{
            a[i][1] -= a[i][0];
            a[i][0] = 0;
        }
    }

    lob.clear();
    hor.clear();

    for(int i=0; i<MX; i++){
        for(int j=1; j<=a[i][0]; j++){
            lob.push_back(pr[i]);
        }
        for(int j=1; j<=a[i][1]; j++){
            hor.push_back(pr[i]);
        }
    }

   // cout << "partha" << endl;
    int lz = lob.size();
    int hz = hor.size();
    double ans;

    if(lz==0 && hz==0){
        return 1.0;
    }
    if(lz==0){
        ans = 1.0;
    }
    else{
        ans = lob[0];
    }



    int x=1,y=0;

    while(x<lz || y<hz)
    {
        if(x<lz){
            double tmp = ans*lob[x];
            if(tmp>inf && y<hz){
                ans /= hor[y];
                y++;
            }
            else{
                ans *= lob[x];
                x++;
            }
        }
        else if(y<hz){
            ans /= hor[y];
            y++;
        }
    }
    return ans;
}
int main()
{
    sieve();
    ll p,q,r,s;
    while(scanf("%lld %lld %lld %lld",&p,&q,&r,&s)==4)
    {
        double ans = solve(p,q,r,s);
        printf("%.5f\n",ans);
    }
    return 0;
}

