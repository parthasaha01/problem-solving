#include<bits/stdc++.h>
using namespace std;
int MAXN = 50000;
int phi[50005],vis[50005],ans[50005];
void EulerPhi()
{
    for(int i=1; i<=MAXN; i++)phi[i]=i;
    for(int i=2; i<=MAXN; i++){
        if(vis[i]==0){
            phi[i] = i-1;
            for(int j=i+i; j<=MAXN; j+=i){
                phi[j] -= phi[j]/i;
                vis[j] = 1;
            }
        }
    }
}
void precalc()
{
    ans[1] = 1;
    for(int i=2; i<=MAXN; i++){
        ans[i] = ans[i-1] + (2*phi[i]);
    }
}
int main()
{
    EulerPhi();
    precalc();

    int n;
    while(scanf("%d",&n))
    {
        if(!n)break;
        printf("%d\n",ans[n]);
    }
    return 0;
}
