#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }

        int flag = -1;

        for(int i=1; i<=n; i++)
        {
            if(a[i]!=b[i]){
                flag = 1;
                break;
            }
        }

        if(flag==1){
            printf("rated\n");
            continue;
        }

        int minn=11111111;
        for(int i=1; i<=n; i++)
        {
            if(a[i]>minn){
                flag=0;
                break;
            }
            minn = min(a[i],minn);
        }

        if(flag==0)printf("unrated\n");
        else printf("maybe\n");
    }
    return 0;
}
