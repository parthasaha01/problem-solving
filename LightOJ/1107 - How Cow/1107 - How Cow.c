#include<stdio.h>
int main()
{
    long int T, x, y, x1, x2, y1, y2, M, i=0;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld %ld %ld %ld", &x1, &y1, &x2, &y2);

        scanf("%ld", &M);

        printf("Case %ld:\n", ++i);

        while(M--)
        {
            scanf("%ld %ld", &x, &y);

            if((x>x1 && x<x2) && (y>y1 && y <y2))
                printf("Yes\n");

            else
                printf("No\n");
        }
    }

    return 0;
}
