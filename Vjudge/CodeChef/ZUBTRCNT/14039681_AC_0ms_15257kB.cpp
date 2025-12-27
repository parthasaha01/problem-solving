#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1;tst<=test;tst++)
    {
        long long int n,l;
        scanf("%lld%lld",&n,&l);

        if(n<l){
            printf("Case %d: 0\n",tst);
            continue;
        }

        long long int m = (n-l+1);

        printf("Case %d: %lld\n",tst,(m*(m+1)/2));

    }

    return 0;
}

