#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,bx,n,b,k,cnt,res;
    scanf("%d",&T);
    int a[105];
    int sum,total;
    while(T--)
    {
        scanf("%d %d",&n,&b);

        total=0;

        for(int i=0; i<b; i++)
        {
            sum=1;
            scanf("%d",&k);

            for(int x=0; x<k; x++)
            {
                scanf("%d",&bx);

                sum *= bx;
                sum = sum%n;
            }

            //scanf("%d",&cnt);
            total += sum;
            total = total%n;
            //printf("sum=%d total=%d\n",sum,total);

        }

        printf("%d\n",total);
    }

    return 0;
}
