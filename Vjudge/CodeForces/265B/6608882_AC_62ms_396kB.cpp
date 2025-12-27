#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }

        //sort(a,a+n+1);

        int res=0;
        res = a[0]+1;
        for(int i=1; i<n; i++)
        {
            res += abs(a[i]-a[i-1])+2;
        }

        printf("%d\n",res);
    }

    return 0;
}
