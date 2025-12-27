#include<stdio.h>
#include<string.h>
int main()
{
    long int sum, i, L, degree, num;
    char str[1005];

    while(scanf("%s", str))
    {
        L = strlen(str);

        if(L == 1 && str[0] == '0')
            break;

        sum=0;
        degree = 1;

        for(i=0; i<L; i++)
        {
            sum += (str[i]-'0');
        }

        if(sum % 9 == 0)
        {
            while(sum>9)
            {
                num = sum;
                sum = 0;

                while(num != 0)
                {
                    sum += (num%10);
                    num = (num/10);
                }
                ++degree;
            }

            printf("%s is a multiple of 9 and has 9-degree %ld.\n", str, degree);
        }
        else
            printf("%s is not a multiple of 9.\n", str);
    }

    return 0;
}
