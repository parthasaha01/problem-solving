#include<bits/stdc++.h>
using namespace std;
#define Mx 1000002
bool vis[Mx+5];
int phi[Mx+5];
void sieve()
{
    for(int i=1; i<=Mx; i++){
        phi[i]=i;
    }

    for (int i=2; i<=Mx; i++)
    {
        if(vis[i]==false)
        {
            phi[i]=i-1;
            for (int j=i+i; j<=Mx; j+=i)
            {
                phi[j] = phi[j]-(phi[j]/i);
                vis[j]=true;
            }
        }
    }
}
int main()
{
    sieve();

    int n,T;

    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << phi[n] << endl;
    }

    return 0;
}

