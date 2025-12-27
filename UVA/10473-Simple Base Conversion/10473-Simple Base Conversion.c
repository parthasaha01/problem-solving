#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

int main ()
{
    long n;
    char a [20];

    while ( gets (a) )
    {
        n = atol (a);

            if ( n < 0 )
                break;

        if ( a [0] == '0' && a [1] == 'x' )
        {
            n = strtol (a, '\0', 16);

            printf ("%ld\n",n);
        }

        else
        {

            printf("0x%X\n", atol ( a ));
        }

    }

    return 0;
}
