#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000000LL
#define ll long long
ll cost[30][30],d[30][30],c[30][30],p[30][30],ls,lt;
string s,t;
void floydWarshall()
{

    for(int i=1; i<=26; i++){
        for(int j=1; j<=26; j++){
            d[i][j] = cost[i][j];
        }
    }

    for(int k=1; k<=26; k++)
    {
        for(int i=1; i<=26; i++)
        {
            for(int j=1; j<=26; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

}
void calculate()
{
    for(int i=1; i<=26; i++)
    {
        for(int j=1; j<=26; j++)
        {
            ll sum = 1000000000000000;
            ll ch = 0;
            for(int k=1; k<=26; k++)
            {
                ll v = d[i][k]+d[j][k];
                if(v<sum)
                {
                    sum = v;
                    ch  = k;
                }
            }

            c[i][j]=sum;
            p[i][j]=ch;
        }
    }
}
int main()
{
    cin>>s>>t;
    ls = s.size();
    lt = t.size();

    int n; scanf("%d",&n);

    for(int i=0; i<29; i++){
        for(int j=0; j<29; j++){
            if(i==j)cost[i][j]=0;
            else cost[i][j] = inf;
        }
    }

    for(int i=1; i<=n; i++)
    {
        string a,b; ll w;
        cin>>a>>b>>w;
        //cout << a << " " << b << " " << w << endl;
        int u = a[0]-'a'+1;
        int v = b[0]-'a'+1;
        cost[u][v] = min(cost[u][v],w);
    }

    if(ls!=lt){
        printf("-1\n");
        return 0;
    }

    floydWarshall();

    calculate();

    string ans;
    ll res=0;

    for(int i=0; i<ls; i++)
    {
        int u = s[i]-'a'+1;
        int v = t[i]-'a'+1;
        res += c[u][v];
        char m = (p[u][v]-1)+'a';
        ans += m;
    }

    if(res>=1000000000000)
    {
        printf("-1\n");
        return 0;
    }

    cout << res << endl;
    cout << ans << endl;

    return 0;

}
