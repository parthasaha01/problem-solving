#include<stdio.h>
int main()
{
    long int N,M;

    while(scanf("%ld", &N)==1 && N != 0)
    {
        if(N <= 100)
        {
            M=91;
        }
        else
        {
            M=N-10;
        }
        printf("f91(%ld) = %ld\n",N,M);
    }

    return 0;
}
