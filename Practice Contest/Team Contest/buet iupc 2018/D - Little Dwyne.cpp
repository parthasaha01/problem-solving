#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    while(tt--)
    {
        int d,k; scanf("%d%d",&d,&k);
        int ans = 0;

        for(int i=1; i<=d; i++){
            int x; scanf("%d",&x);
            if(x>k)ans += (x-k);
        }
        printf("%d\n",ans);
    }
    return 0;
}
