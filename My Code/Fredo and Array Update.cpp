#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    printf("partha\n");
    while(scanf("%d",&n)==1)
    {
        int sum=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int v = sum/n;
        v++;
        printf("%d\n",v);
    }
    return 0;
}
