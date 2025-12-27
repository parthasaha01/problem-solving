#include<bits/stdc++.h>
using namespace std;
int pw[]={1,2,4,8,16,32,64,128,256};
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int f[10],f1[10];

        scanf("%d.%d.%d.%d",&f[1],&f[2],&f[3],&f[4]);
        scanf("%d.%d.%d.%d",&f1[1],&f1[2],&f1[3],&f1[4]);

        bool flag=true;

        for(int k=1; k<=4; k++)
        {
            int m=f1[k];
            int p=0;
            int n=0;

            while(m!=0)
            {
                int r=m%10;
                m=m/10;
                if(r==1){
                    n+=pw[p];
                }
                p++;
            }

            if(n!=f[k]){
                flag=false;
                break;
            }
        }

        if(flag)
            printf("Case %d: Yes\n",kase);
        else
            printf("Case %d: No\n",kase);
    }

    return 0;
}
