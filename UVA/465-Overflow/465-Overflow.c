#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    long double x, y, result;
    char ch, a[500], b[500];

    while(scanf("%s %c %s", a, &ch, b) == 3)
    {

        x = atof(a);
        y = atof(b);

        switch(ch)
        {
            case '+' :
                result = x+y;
                break;

            default:
                result = x*y;
        }

            printf("%s %c %s\n", a, ch, b);


            if(x > 2147483647)
                printf("first number too big\n");

            if(y > 2147483647)
                printf("second number too big\n");

            if(result > 2147483647)
                printf("result too big\n");
    }

    return 0;
}
