#include<stdio.h>
#include<string.h>
int main()
{
    long int i, length, num, rem;
    char str[1005];

    while(gets(str))
    {
        length = strlen(str);
        num = 0;

        if(length ==1 && str[0] == '0')
            break;

        for(i=0; i<length; i++)
        {
            num += str[i] - '0';

            rem = num%17;
            num = (rem*10);
        }

        if(rem == 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
