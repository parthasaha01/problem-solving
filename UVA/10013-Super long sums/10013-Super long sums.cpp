#include<iostream>
#include<cstdio>
#include<cstring>
#define Mn 1000002
long int a[Mn];
long int b[Mn];
long int res[Mn];
using namespace std;
int main()
{
    long int T, M, i, L, carry, sum;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &M);

        for(i=0; i<M; i++)
        {
            scanf("%ld %ld", &a[i], &b[i]);
        }

        carry=0;

        for(i=M-1; i>=0; i--)
        {
            sum = (carry+a[i]+b[i]);
            res[i] = sum%10;
            carry = sum/10;
        }

        for(i=0; i<M; i++)
            printf("%ld", res[i]);

        if(T)
            printf("\n\n");
        else
            printf("\n");

    }

    return 0;
}
