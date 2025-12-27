#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long int i, j, num, prime, L;
    double root;
    char str[25];

    while(gets(str))
    {
        num = 0;
        prime = 1;
        L=strlen(str);
        str[L] = '\0';

        for(i=0; i<L; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                num += (str[i] - 'a' + 1);
            else
                num += (str[i] - 'A' + 27);
        }

        if(num == 1 || num == 2)
            prime = 1;
        else if(num%2 == 0)
            prime = 0;
        else
        {
            root = sqrt(num);

            for(j=3; j <= (int)root; j += 2)
            {
                if(num%j == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }

        if(prime == 1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }

    return 0;
}
