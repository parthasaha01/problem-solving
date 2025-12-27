#include<stdio.h>
#include<string.h>
int main()
{
    long int L1, L2, L3, i, j, k, x, y, num, rem;
    char str1[150], str2[150], str3[150];

        scanf("%s", str1);

        while(scanf("%s", str2))
        {
            L1 = strlen(str1);
            L2 = strlen(str2);

            str2[L2] = '\0';

            if(L2 == 1 && str2[0] == '0')
            break;

            num = 0;
            k=0;

            for(i=L1-1, j=L2-1; i>=0 && j >=0; i--, j--)
            {
                num += (str1[i]-'0') + (str2[j]-'0');
                rem = (num%10);
                str3[k] = rem+'0';
                ++k;
                num = (num/10);
            }

            if(L1 != L2)
            {
                if(L1>L2)
                {
                    while(i>=0)
                    {
                        num += (str1[i] - '0');
                        rem = (num%10);
                        str3[k] = rem+ '0';
                        num = (num/10);
                        ++k;
                        --i;
                    }

                }
                else
                {
                    while(j>=0)
                    {
                        num += (str2[j] - '0');
                        rem = (num%10);
                        str3[k] = rem+ '0';
                        num = (num/10);
                        ++k;
                        --j;
                    }
                }
            }

            if(num != 0)
            {
                str3[k] = num+'0';
                ++k;
            }

            str3[k] = '\0';

            L3 = strlen(str3);

            for(x=0, y=L3-1; x<L3; x++,--y)
            {
                str1[x] = str3[y];
            }

            str1[k] = '\0';
        }

    puts(str1);

    return 0;
}
