#include<stdio.h>
void Ternary(long n)
{
    if(n==0)
        return ;
    Ternary(n/3);
    printf("%ld",n%3);
}
int main()
{
    long N;

    while(scanf("%ld",&N) && N>=0)
    {
        if(N==0){
            printf("0\n");
            continue;
        }
        Ternary(N);
        printf("\n");
    }

    return 0;
}
