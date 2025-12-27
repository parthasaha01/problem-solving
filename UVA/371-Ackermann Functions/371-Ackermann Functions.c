#include<stdio.h>
int main()
{
    long int L, H, temp, V, v, r, R, i;

    while(scanf("%ld %ld", &L, &H) == 2)
    {
        if(L == 0 && H == 0)
            break;

        if(L > H)
        {
            temp = L;
            L = H;
            H = temp;
        }

        R = 0;

        for(i=L; i <= H; i++)
        {
            v=i;
            r = 0;
            if(v==1)
            {
                V=1;
                R=3;
            }
            while(v != 1)
            {
                if(v%2 == 0)
                {
                    v = v/2;
                    ++r;
                }
                else
                {
                    v = 3*v+1;
                    ++r;
                }
            }

            if(r>R)
            {
                R=r;
                V=i;
            }

        }

        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", L, H, V, R);

    }

    return 0;
}
