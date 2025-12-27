#include<stdio.h>
#include<math.h>
#define MAX 1000000
int main()
{
    long num, i, sq, j;

    while(scanf("%ld", &num)==1)
    {

        if(num == 2)
            printf("Prime\n");
        else if(num<2 || num%2 == 0)
            printf("Not Prime\n");
        else
        {
            int status[MAX] = {0};

            sq = (long)(sqrt((double)num));

            for(i=3; i <= sq; i += 2)
            {
                if(status[i] == 0)
                {
                    for(j = i*i; j <= num; j += 2*i)
                        status[j] = 1;
                }

            }

            if(status[num] == 1)
                printf("Not Prime\n");
            else
                printf("Prime\n");
        }



    }
}
