#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define mod 1000000007
vector<int>v[mx];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1; i<=n; i++){
            int g; scanf("%d",&g);
            for(int j=1; i<=g; j++){
                int x; scanf("%d",&x);
                v[x].push_back(i);
            }
        }


    }

    return 0;
}
