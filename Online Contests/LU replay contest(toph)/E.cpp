#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mx 100001
int n,a[mx+5],x[mx+5],z[mx+5],m[mx+5];
bool flag[500];
vector<int>pr;
void sieve()
{
    pr.push_back(2);
    for(int i=3; i<=320; i+=2){
        if(!flag[i]){
            pr.push_back(i);
            for(int j=i*i; j<=320; j+=(i+i)){
                flag[j]=true;
            }
        }
    }
}
int main()
{
    sieve();

    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
        }

        z[0]=0;
        for(int i=1; i<=n; i++){
            if(a[i]==0)z[i]=z[i-1]+1;
            else z[i]=z[i-1];
        }

        m[0]=0;
        for(int i=1; i<=n; i++){
            if(a[i]<0)m[i]=m[i-1]+1;
            else m[i]=m[i-1];
        }

        x[0]=0;
        for(int i=1; i<=n; i++)
        {
            int v = abs(a[i]);
            x[i] = x[i-1];

            for(int k=0; k<pr.size() && pr[k]*pr[k]<=v; k++)
            {
                while(v%pr[k]==0)
                {
                    x[i] ^= pr[k];
                    v /= pr[k];
                }
            }
            if(v>1) x[i] ^= v;
        }

        for(int i=1; i<=q; i++)
        {
            int lf,rg;
            scanf("%d%d",&lf,&rg);
            if(lf>rg)swap(lf,rg);

            if(z[rg]-z[lf-1]>0){
                printf("Yes\n");
                continue;
            }

            if((m[rg]-m[lf-1])%2==1){
                printf("No\n");
                continue;
            }

            if((x[rg]^x[lf-1])==0) printf("Yes\n");
            else printf("No\n");
        }

    }
    return 0;
}
