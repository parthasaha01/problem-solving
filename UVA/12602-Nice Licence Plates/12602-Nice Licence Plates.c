#include<stdio.h>
int main()
{
    long int A, B, C, letter, digit, N, diff;
    char a,b,c,d;

    scanf("%ld", &N);
    getchar();

    while(N--)
    {
        scanf("%c %c %c %c %ld", &a, &b, &c, &d, &digit);
        getchar();

        A = a-'A';
        B = b-'A';
        C = c-'A';

        letter = (A*(26*26)) + (B*26) + C;

        diff = digit - letter;

        if(diff < 0)
            diff = -diff;

        if(diff > 100)
            printf("not nice\n");
        else
            printf("nice\n");
    }

    return 0;
}
