#include<stdio.h>
int main()
{
    long int T,L,W,H,i;

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld %ld",&L,&W,&H);

        if(L<=20 && W<=20 && H<=20)
        {
            printf("Case %ld: good\n",i);
        }
        else
        {
            printf("Case %ld: bad\n",i);
        }
    }

    return 0;
}
