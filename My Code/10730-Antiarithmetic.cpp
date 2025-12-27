#include<bits/stdc++.h>
using namespace std;
int n,a[10005],fr[10005];
int main()
{
    while(scanf("%d",&n) && n)
    {
        getchar();

        memset(fr,0,sizeof(fr));

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            fr[a[i]]=i;
        }

        bool flag = true;
        for(int i=1; i<=n-2; i++)
        {
            for(int j=i+1; j<=n-1; j++)
            {
                int d = a[j]-a[i];
                int k = a[j]+d;
                if(k>=0){
                    if(fr[k]>j){
                        flag=false;
                        goto label;
                    }
                }
            }
        }

        label:

        if(flag)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
