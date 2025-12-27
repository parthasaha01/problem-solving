#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++){
            int x; scanf("%d",&x);
            vv.push_back(x);
        }

        for(int i=1; i<=k; i++){
            vv.push_back(1000);
        }

        sort(vv.begin(),vv.end());

        int sz = vv.size();

        printf("%d\n",vv[sz/2]);

        vv.clear();
    }
    return 0;
}
