#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000005
ll a[105][105];
int main()
{
    ll n,m,k,x,y;

    while(cin>>n>>m>>k>>x>>y)
    {
        memset(a,0,sizeof(a));

        if(n==1){
            ll mx,mn,sr;
            if(k%m==0)mx = k/m;
            else mx = (k/m)+1;

            mn = k/m;
            if(y<=k%m)sr=mx;
            else sr=mn;
            cout << mx << " " << mn << " " << sr << endl;
            continue;
        }
        if(n==2){
            ll each = (k/(2*m));
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    a[i][j] = each;
                }
            }
            ll rm = k-(n*m*each);
            for(int i=1; i<=n&&rm; i++){
                for(int j=1; j<=m&&rm; j++){
                    a[i][j]++;
                    rm--;
                }
            }
            ll mx=0,mn=inf,sr=a[x][y];
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    mx = max(mx,a[i][j]);
                    mn = min(mn,a[i][j]);
                }
            }
            cout << mx << " " << mn << " " << sr << endl;
            continue;
        }

        ll d=k;
        if(d>=n*m){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    a[i][j]=1;
                }
            }
            d-=(n*m);
        }

        ll each = (n*m)-m;

        ll cn = (d/(2*each));

        for(int i=2; i<=n-1; i++){
            for(int j=1; j<=m; j++){
                a[i][j]+=2*cn;
            }
        }

        ll kn = (d/each);
        for(int j=1; j<=m; j++){
            a[1][j] += (kn+1)/2;
            a[n][j] += (kn/2);
        }

        ll rm = d - (cn*each*2);

        for(int i=n-1; i>=1 && rm; i--){
            for(int j=1; j<=m && rm; j++){
                a[i][j]++;
                rm--;
            }
        }

        for(int i=2; i<=n && rm; i++){
            for(int j=1; j<=m && rm; j++){
                a[i][j]++;
                rm--;
            }
        }

        ll mx=0,mn=inf,sr=a[x][y];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                mx = max(mx,a[i][j]);
                mn = min(mn,a[i][j]);
            }
        }

        cout << mx << " " << mn << " " << sr << endl;
    }

    return 0;
}

