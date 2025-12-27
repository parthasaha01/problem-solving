#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t; scanf("%d",&t);

    while(t--)
    {
        int n; scanf("%d",&n);

        int odd = 0;
        int even = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==0)even++;
            else odd++;
        }

        if(n==1){
            printf("1\n");
            continue;
        }
        if(odd%2==0){
            printf("1\n");
            continue;
        }
        else{
            printf("2\n");
            continue;
        }

    }
    return 0;
}
