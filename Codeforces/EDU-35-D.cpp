#include<bits/stdc++.h>
using namespace std;
int a[1505];
int main()
{
    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    int tot=0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i]>a[j])tot++;
        }
    }

    int q; scanf("%d",&q);

    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        if(l>r)swap(l,r);

        int x = r-l+1;
        int sum = (x*(x-1))/2;
        int ans = tot-sum;

        if(ans&1)printf("odd\n");
        else printf("even\n");

        tot = ans;
    }

    return 0;
}
