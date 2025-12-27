#include<stdio.h>
#include<math.h>
int main()
{
    long long a, b, i, temp, L1, L2, L3, dec, digit;
    char str1[10000], str2[10000], str3[10000];

    while(scanf("%lld %lld", &a, &b)==2)
    {
        if(a == b)
        {
            printf("0\n");
        }
        else
        {
            if(a>b)
            {
                temp=a;
                a=b;
                b=temp;
            }
            i=0;

            while(b != 0)
            {
                str1[i] = (b%2) + '0';
                b = b/2;
                ++i;
            }
            str1[i] = '\0';
            L1=i;
            i=0;

            while(a != 0)
            {
                str2[i] = (a%2) + '0';
                a=a/2;
                ++i;
            }
            str2[i] = '\0';
            L2=i;

            for(i=0; i<L2; i++)
            {
                if(str1[i] == str2[i])
                    str3[i] = '0';
                else
                    str3[i] = '1';
            }
            while(i<L1)
            {
                str3[i] = str1[i];
                i++;
            }
            str3[i] = '\0';
            L3=i;
            dec=0;

            for(i=0; i<L3; i++)
            {
                digit = str3[i] - '0';
                dec += digit*(pow(2,i));
            }

            printf("%lld\n", dec);

        }
    }

    return 0;
}
