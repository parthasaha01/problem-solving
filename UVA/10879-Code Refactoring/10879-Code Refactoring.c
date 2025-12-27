#include<stdio.h>
#include<math.h>
int main()
{
    long long T, num, A, B, C, D, i, p, test=1;
    double sqt;

    scanf("%lld", &T);

    while(T--)
    {
        scanf("%lld", &num);
        sqt = sqrt((double)num);
        p=0;

        for(i=2; i<=(int)sqt; i++)
        {
            if(num%i == 0 )
            {
                if(p==0)
                {
                    A = i;
                    B = num/i;

                    if(A == B)
                        continue;
                    p=1;
                }
                else
                {
                    C = i;
                    D = num/i;

                    if(A == D || B == C || B == D || C == D || A == C)
                        continue;

                    break;
                }
            }
        }

        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n", test++, num, A, B, C, D);
    }

    return 0;
}
