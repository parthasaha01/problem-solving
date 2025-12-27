#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int qq; scanf("%d",&qq);

    a[1]=a[2]=a[3]=a[5]=a[7]=a[11]=-1;
    a[8]=a[10]=2;
    a[4]=a[6]=a[9]=1;

    while(qq--)
    {
        int n; scanf("%d",&n);

        if(n<=11)
        {
            printf("%d\n",a[n]);
        }
        else
        {
            if(n%2==0)
            {
                printf("%d\n",n/4);
            }
            else
            {
                printf("%d\n",(n/4)-1);
            }

        }
    }

    return 0;
}
