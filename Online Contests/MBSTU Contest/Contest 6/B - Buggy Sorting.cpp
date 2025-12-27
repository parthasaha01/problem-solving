#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[55];

    while(scanf("%d",&n)==1)
    {
        if(n<=2){
            printf("-1\n");
            continue;
        }

        int val=99;
        for(int i=0; i<n; i++){
            a[i]=val--;
        }

        for(int i=0; i<n-1; i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }

    return 0;
}
