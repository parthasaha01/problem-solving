#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[10005];
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        a[n]=a[0];
        a[n+1]=a[1];
        n+=2;
        int cnt=0;

        for(int i=1; i<n-1; i++){
            if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
                cnt++;
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
