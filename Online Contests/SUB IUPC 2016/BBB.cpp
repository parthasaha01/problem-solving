#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int sum = (n*(n+1))/2;

        int m; scanf("%d",&m);

        for(int i=1; i<=m; i++){
            int x; scanf("%d",&x);
            sum -= x;
        }
        printf("%d\n",sum);
    }
    return 0;
}
