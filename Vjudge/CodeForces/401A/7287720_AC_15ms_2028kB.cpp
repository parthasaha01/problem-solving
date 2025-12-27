#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;

    while(scanf("%d%d",&n,&x)==2)
    {
        int sum=0;
        for(int i=0; i<n; i++){
            int v;
            scanf("%d",&v);
            sum+=v;
        }
        sum=abs(sum);
        int cnt=0;

        if(sum)
        {
            int p=x;
            while(sum!=0)
            {
                cnt+=(sum/p);
                sum=sum%p;
                p--;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
