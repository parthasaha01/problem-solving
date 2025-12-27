#include<stdio.h>
int main()
{
    long int T, i=0, my_pos, lift_pos, time;

    scanf("%ld", &T);

    while(T--)
    {
            scanf("%ld %ld", &my_pos, &lift_pos);

            if(my_pos <= lift_pos)
                time = (4*lift_pos) + 19;

            else
                time = 4*(my_pos - lift_pos) + (4*my_pos) + 19;

            printf("Case %ld: %ld\n", ++i, time);
    }

    return 0;
}
