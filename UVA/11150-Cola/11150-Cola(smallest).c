#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d", &N) == 1)
    {
            printf("%d\n",N+(N>>1));
    }
    return 0;
}
