#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int sum=0,each=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            //b[a[i]]=i;
            sum+=a[i];
        }

        each = sum/(n/2);
        int need;

        for(int i=1; i<=n/2; i++)
        {
            int flag=0;
            for(int j=1; j<=n; j++)
            {
                if(b[j]==0)
                {
                    if(flag==0){
                        printf("%d ",j);
                        flag=1;
                        need = each-a[j];
                        b[j]=1;
                    }
                    else{
                        if(a[j]==need)
                        {
                            printf("%d\n",j);
                            b[j]=1;
                            break;
                        }
                    }
                }
            }
        }


    }

    return 0;

}
