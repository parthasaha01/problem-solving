#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    long int digit,length,dec,power,i;
    char num[100];

    while(scanf("%s",&num))
    {
        dec=0;
        length=strlen(num);
        for(i=0; i<length; i++)
        {
            digit=num[i]-'0';
            power=length-i;
            dec += digit*(pow(2, power)-1);
        }

        if(dec == 0)
            break;

        printf("%ld\n",dec);
    }

    return 0;
}
