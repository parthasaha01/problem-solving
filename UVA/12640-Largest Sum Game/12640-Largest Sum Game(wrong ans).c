#include<stdio.h>
#include<string.h>
int main()
{
    long long Max, i, sum, num, L;
    char str[1000000];

    while(gets(str))
    {
        L = strlen(str);
        Max=sum=0;

        if(L==0)
            continue;

        for(i=0; i<L; i++)
        {
            num=0;
            while(str[i] != ' ' && i<L)
            {
                num = (num*10) + (str[i++]-'0');
            }

            sum += num;

            if(sum < 0)
                sum = 0;
            else
            {
                if(sum > Max)
                    Max = sum;
            }
        }

        if(Max > 0)
            printf("%lld\n", Max);
        else
            printf("0\n");
    }

    return 0;
}

