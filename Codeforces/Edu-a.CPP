#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        int x; scanf("%d",&x);

        bool flag = false;

        for(int i=0; i<=33; i++)
        {
            for(int j=0; j<=14; j++)
            {
                int tot = (i*3) + (j*7);
                if(x==tot){
                    flag = true;
                    break;
                }
            }

            if(flag == true)break;
        }

        if(flag)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
