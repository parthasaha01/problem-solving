#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ks=0,n;
    while(scanf("%d",&n) && n)
    {
        int cn1=0,cn2=0,v;
        for(int i=0; i<n; i++){
            scanf("%d",&v);
            if(v)cn1++;
            else cn2++;
        }

        printf("Case %d: %d\n",++ks,cn1-cn2);
    }
    return 0;
}
