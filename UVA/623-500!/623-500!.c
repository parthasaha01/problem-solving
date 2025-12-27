#include<stdio.h>
#define MAX 10000

void factorial_of(int);
void multiply(int);

int fact[MAX], length;

int main()
{
    int num;
    int i;

    while(scanf("%d", &num) == 1)
    {
        fact[0]=1;
        length = 0;

        factorial_of(num);

        printf("%d!\n", num);

        for(i=length; i >= 0; i--)
        {
            printf("%d", fact[i]);
        }

        printf("\n");
    }

    return 0;
}

void factorial_of(int num)
{
    int x;

    for(x=2; x<=num; x++)
    {
         multiply(x);
    }
}

void multiply(int x)
{
    long y, r=0, p;

    int ara[MAX];

    for(y=0; y<=length; y++)
    {
            ara[y]=fact[y];
    }

    for(y=0; y<=length; y++)
    {
        p = (ara[y] * x) + r;

         fact[y] = p % 10;

         r = p / 10;
    }

    if(r != 0)
    {
         while(r != 0)
         {
             fact[y] = r%10;

             r= r/10;

             y++;
         }
    }

    length = y-1;
}
