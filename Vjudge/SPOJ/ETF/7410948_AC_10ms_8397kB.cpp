#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
bool vis[mx+5];
int phi[mx+5];
vector<int>pr;
int EulerPhi()
{
    phi[1]=1;
    for(int i=2; i<=mx; i++)
    {
        if(vis[i]==false)
        {
            phi[i]=i-1;
            pr.push_back(i);
        }

        for(int j=0; j<pr.size() && i*pr[j]<=mx; j++)
        {
            vis[i*pr[j]]=true;

            if(i%pr[j]==0)
            {
                phi[i*pr[j]] = phi[i]*pr[j];
                break;
            }
            else
            {
                phi[i*pr[j]] = phi[i]*phi[pr[j]];
            }
        }
    }
}
int main()
{
    EulerPhi();

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }

    return 0;
}
