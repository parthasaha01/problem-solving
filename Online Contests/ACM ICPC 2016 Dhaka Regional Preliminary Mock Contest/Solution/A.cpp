#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);

        if(n>=0)
        {
            for(int i=0; i<n; i++){
                printf("%d ",i);
            }
            printf("%d\n",n);
        }
        else
        {
            for(int i=n; i<0; i++)
            {
                printf("%d ",i);
            }
            printf("0\n");
        }
    }

    return 0;
}
