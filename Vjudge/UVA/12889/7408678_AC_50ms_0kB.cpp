#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        int n;
        scanf("%d",&n);
        int sum=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        sort(a+1,a+n+1);

        if(sum==0||n==1||a[1]==a[n]){
            printf("Better luck next time!\n");
            continue;
        }

        if(a[1]==0){
            printf("Happy Birthday Tutu!\n");
            continue;
        }
        printf("Happy Birthday Tutu!\n");
    }

    return 0;
}
