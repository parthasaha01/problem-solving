#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
int phi[MAXN+5],depth[MAXN+5],cum[MAXN+5];
void totientPhi()
{
    for(int i=1; i<=MAXN; i++)phi[i]=i;
    for(int i=2; i<=MAXN; i++){
        if(phi[i]==i){
            for(int j=i; j<=MAXN; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
void depthPhi()
{
    depth[1] = 0;
    for(int i=2; i<=MAXN; i++){
        depth[i] = 1+depth[phi[i]];
    }

    cum[0]=cum[1]=0;
    for(int i=2; i<=MAXN; i++){
        cum[i] = cum[i-1]+depth[i];
    }
}
int main()
{
    totientPhi();
    depthPhi();

    int tt; scanf("%d",&tt);
    while(tt--)
    {
        int m,n; scanf("%d%d",&m,&n);
        if(m>n)swap(m,n);
        int ans = cum[n]-cum[m-1];
        printf("%d\n",ans);
    }
    return 0;
}
