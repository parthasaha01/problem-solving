#include<bits/stdc++.h>
using namespace std;
#define mx 105
int main()
{
    int m,x,y,dx,dy,k,flag;

    while(scanf("%d",&m)==1)
    {
        int a[mx],s[mx];
        s[0]=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }

        scanf("%d %d",&x,&y);
        flag=0;
        for(int i=1; i<=m; i++)
        {
            dx=s[i-1];
            dy=s[m]-dx;

            if((dx>=x && dx<=y) && (dy>=x && dy<=y))
            {
                flag=1;
                k=i;
                break;
            }
        }

        if(flag==1)
            printf("%d\n",k);
        else
            printf("0\n");
    }

    return 0;
}
