#include <stdio.h>
int main()
{
    long int d1, m1, y1, d2, m2, y2, age, T, i;

    scanf("%ld",&T);

        for(i=1;i<=T;i++)
        {

            scanf("%ld",&d1);
            getchar();
            scanf("%ld",&m1);
            getchar();
            scanf("%ld",&y1);

            scanf("%ld",&d2);
            getchar();
            scanf("%ld",&m2);
            getchar();
            scanf("%ld",&y2);

            age=(y1-y2);

            if(m1<m2)
                --age;
            else if(m1==m2 && d1<d2)
                --age;

            if(age<0)
                printf("Case #%ld: Invalid birth date\n", i );

            else if(age>130)
                printf("Case #%ld: Check birth date\n", i);

            else
                printf("Case #%ld: %ld\n",i,age);
        }

        return 0;
}
