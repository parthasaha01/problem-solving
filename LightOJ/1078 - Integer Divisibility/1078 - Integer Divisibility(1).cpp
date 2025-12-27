#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,d,rem,D;
    int T,test,Count,i,j,nlen;

    scanf("%d",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%ld %ld",&n,&d);
        Count=1;
        D=d;

        while(1)
        {
            if(D<n)
            {
                D = (D*10)+d;
                Count++;
            }

            rem = D%n;

            if(rem == 0)
                break;
            else
                D=rem;
        }

        printf("Case %d: %d\n",test,Count);

    }

    return 0;
}
