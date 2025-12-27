#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);

    for(int test=1; test<=t; test++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",test,(n<<1)-1);
    }
    return 0;
}
