#include<bits/stdc++.h>
using namespace std;
int n,a[10005],fr[10005];
int main()
{
    while(scanf("%d",&n) && n)
    {
        getchar();

        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            fr[a[i]]=i;
        }

        flag = true;



        if(flag)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

