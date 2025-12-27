#include<stdio.h>
int main()
{
    long long i=0, A, L, num, term;

    while(scanf("%lld %lld", &A, &L)==2)
    {
        if(A<0 && L<0)
            break;

        num = A;
        term = 0;

        while(num != 1 && num <= L)
        {
            if(num%2 == 0)
                num = num/2;
            else
                num = (num*3)+1;

            ++term;
        }

        if(num == 1)
            ++term;

        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", ++i, A, L, term);
    }

    return 0;
}
