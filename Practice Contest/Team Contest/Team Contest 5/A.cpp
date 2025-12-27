#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==-1)break;
        int sum = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if(sum%n==0)
        {
            int each = sum/n;
            int ret = 0;
            for(int i=1; i<=n; i++){
                if(a[i]>each){
                    ret += a[i]-each;
                }
            }

            printf("%d\n",ret);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
