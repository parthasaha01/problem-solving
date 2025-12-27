#include<stdio.h>
#include<string.h>
int main()
{
    long int I, parity, i, j, length;
    char str1[35], str2[35];

    while(scanf("%ld", &I)==1 && I != 0)
    {
        parity=0;
        i=0;

        while( I != 0)
        {
            str1[i] = (I%2) + '0';
            I = I/2;
            ++i;
        }

        str1[i] = '\0';

        for(j=0; i>0; i--, j++)
        {
            str2[j] = str1[i-1];
        }

        str2[j] = '\0';
        length = strlen(str2);

        for(j=0; j < length; j++)
        {
            if(str2[j] == '1')
                ++parity;
        }

        printf("The parity of %s is %ld (mod 2).\n", str2, parity);
    }

    return 0;
}
