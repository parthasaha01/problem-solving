#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
int a[1000];
int main()
{
    int n;
    while(cin>>n)
    {
        int maxx = -100000000;
        int sum=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            maxx = max(maxx,a[i]);
        }

        int total = maxx*n;
        int need = total - sum;
        printf("%d\n",need);
    }

    return 0;
}
