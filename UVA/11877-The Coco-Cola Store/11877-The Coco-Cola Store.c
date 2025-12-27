#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%d\n",n>>1);        // (n>>1) = n/2
    }
    return 0;
}
