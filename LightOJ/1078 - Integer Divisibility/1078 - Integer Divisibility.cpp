#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,d,rem;
    int T,test,Count;

    scanf("%d",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%ld %ld",&n,&d);
        rem = d%n;
        Count=1;

        while(rem)
        {

            rem = (rem*10+d)%n;
            Count++;

        }

        printf("Case %d: %d\n",test,Count);

    }

    return 0;
}
