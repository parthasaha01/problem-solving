#include<stdio.h>
int main()
{
    long int N, M, dec, hex, num, rem;

    scanf("%ld", &N);

    while(N--)
    {
        scanf("%ld", &M);

        dec=hex=0;
        num = M;

        while(num != 0)
        {
            rem = num%2;
            num = num/2;

            if(rem == 1)
                ++dec;
        }

        num = M;

        while(num != 0)
        {
            rem = num%10;
            num = num/10;

            switch(rem)
            {
                case 1:
                case 2:
                case 4:
                case 8:
                    hex += 1;
                    break;
                case 3:
                case 5:
                case 6:
                case 9:
                    hex += 2;
                    break;
                case 7:
                    hex += 3;
                    break;
            }
        }

        printf("%ld %ld\n",dec,hex);
    }

    return 0;
}
