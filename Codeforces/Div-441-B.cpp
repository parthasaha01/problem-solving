#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[100005],fr[100005];
int main()
{
    scanf("%d%d%d",&n,&k,&m);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    int ans=1;
    int flag=-1;
    for(int i=1; i<=n; i++)
    {
        int rm = a[i]%m;
        fr[rm]++;

        if(fr[rm]==k)
        {
            ans=rm;
            flag=1;
            break;
        }
    }

    if(flag==-1)
    {
        printf("No\n");
    }
    else
    {
        int suru=0;
        printf("Yes\n");
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]%m==ans)
            {
                cnt++;
                if(suru==0)
                {
                    printf("%d",a[i]);
                    suru=1;
                }
                else
                {
                    printf(" %d",a[i]);
                    suru=1;
                }

                if(cnt==k)break;
            }
        }
        printf("\n");
    }

    return 0;
}
