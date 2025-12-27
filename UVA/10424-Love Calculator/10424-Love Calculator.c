#include<stdio.h>
#include<string.h>
int main()
{
    long int i, L1, L2, sum1, sum2, num1, num2;
    double love;
    char str1[30], str2[30];

    while(gets(str1))
    {
        gets(str2);

        L1 = strlen(str1);
        L2 = strlen(str2);

        sum1 = 0;
        sum2 = 0;

        for(i=0; i<L1; i++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
                sum1 += ((str1[i]-'A') + 1);
            else if(str1[i] >= 'a' && str1[i] <= 'z')
                sum1 += ((str1[i]-'a') + 1);
        }

        for(i=0; i<L2; i++)
        {
            if(str2[i] >= 'A' && str2[i] <= 'Z')
                sum2 += (str2[i]-'A') + 1;
            else if(str2[i] >= 'a' && str2[i] <= 'z')
                sum2 += (str2[i]-'a') + 1;
        }

        while(sum1 > 9)
        {
            num1 = sum1;
            sum1 = 0;

            while(num1 != 0)
            {
                sum1 += (num1%10);
                num1 = num1/10;
            }
        }
        while(sum2 > 9)
        {
            num2 = sum2;
            sum2=0;

            while(num2 != 0)
            {
                sum2 += (num2%10);
                num2 = num2/10;
            }
        }

        if(sum1>sum2)
            love = ((sum2)/(double)(sum1) ) * 100;
        else
            love = ((sum1)/(double)(sum2)) * 100;

        printf("%.2lf %%\n", love);
    }

    return 0;
}
