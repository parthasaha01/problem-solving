#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long int n,m, c;

    while(scanf("%lld %lld", &n, &m) != EOF)
    {
        //c = m-n;

        //if(c<0)
        //{
            //printf("%ld\n",-c);
        //}
        //else
        //{
            printf("%lld\n",abs(m-n));
        //}
    }

    return 0;
}
