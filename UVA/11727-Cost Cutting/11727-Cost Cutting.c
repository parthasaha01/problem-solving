#include<stdio.h>
int main()
{
    int T,a,b,c,i;

    scanf("%d",&T);

    for(i=1; i<= T; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ",i);

        if(a>b && a<c)
        {
            printf("%d\n",a);
        }
        else if(a<b && a>c)
        {
            printf("%d\n",a);
        }
        else if(a<b && b<c)
        {
            printf("%d\n",b);
        }
        else if(a>b && b>c)
        {
            printf("%d\n",b);
        }
        else
        {
            printf("%d\n",c);
        }
    }

    return 0;
}
