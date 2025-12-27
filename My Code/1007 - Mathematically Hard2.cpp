#include<bits/stdc++.h>
using namespace std;
#define mx 5000005
#define ll unsigned long long int
ll phi[mx];
int p[350000];
bool vis[mx];
void totientPhi()
{
    int cnt=0;
    phi[1] = 0;

    for (int i=2; i<mx; i++)
    {
        if (!vis[i])
        {
            p[cnt++] = i;
            phi[i] = i-1;
        }
        for (int j=0; j<cnt && i*p[j]<mx; j++)
        {
            vis[i*p[j]] = true;
            if (i%p[j])
            {
                phi[i*p[j]]=phi[i]*phi[p[j]];
            }
            else
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
        }
    }

    for(int i=2; i<mx; i++){
        phi[i]=phi[i-1]+(phi[i]*phi[i]);
    }
}
int main()
{
    totientPhi();
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ll ans=phi[b]-phi[a-1];
        printf("Case %d: %llu\n",kase,ans);
    }

    return 0;
}

/*
8
6 6
8 8
2 20
2 5000000
5000000 5000000
4000000 5000000
4999999 5000000
4999999 4999999
*/
