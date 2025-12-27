#include<stdio.h>
int main()
{
    long int a, b, press;

    while(scanf("%ld %ld", &a, &b) == 2)
    {
        if(a == -1 && b == -1)
            break;

        press = b-a;

        if(press < 0)
            press = -press;

        if(press > 50)
            press = 100-press;

        printf("%ld\n", press);
    }

    return 0;
}
