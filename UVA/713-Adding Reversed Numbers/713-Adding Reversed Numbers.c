#include<stdio.h>
#include<string.h>
int main()
{
    long int T, i, j, k, L1, L2, L3, p, a, b, hand, sum;
    char str1[500], str2[500], str3[500], rev1[500], rev2[500], rev3[500];

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        j=0;

        scanf("%s %s", str1, str2);

        L1 = strlen(str1);
        L2 = strlen(str2);

        for(i=L1-1; i >= 0; i--)
        {
                rev1[j++] = str1[i];
        }

        rev1[j] = '\0';

        L1 = j;
        j=0;

        for(i = L2-1; i >=0; i--)
        {
                rev2[j++] = str2[i];
        }

        rev2[j] = '\0';

        L2=j;

        hand  = 0;
        k = 0;
        p=0;

        if(L1 >= L2)
        {
            for(i = L1-1, j=L2-1; i >= 0; i--)
            {
                if(j < 0)
                {
                    a = rev1[i]-'0';
                     sum = a+hand;

                     if(p==1 || sum != 10)
                     {
                         str3[k++] = (sum%10) + '0';
                         p=1;
                     }

                     hand = sum/10;
                }
                else
                {
                    a = rev1[i] - '0';
                    b = rev2[j]-'0';

                    sum = a+b+hand;

                    if(p==1 || sum != 10)
                     {
                         str3[k++] = (sum%10) + '0';
                         p=1;
                     }

                    hand = sum/10;
                    --j;
                }

            }
        }
        else
        {
            for(i = L2-1, j=L1-1; i >= 0; i--)
            {
                if(j < 0)
                {
                    a = rev2[i]-'0';
                     sum = a+hand;

                     if(p==1 || sum != 10)
                     {
                         str3[k++] = (sum%10) + '0';
                         p=1;
                     }

                     hand = sum/10;
                }
                else
                {
                    a = rev2[i] - '0';
                    b = rev1[j]-'0';

                    sum = a+b+hand;

                    if(p==1 || sum != 10)
                     {
                         str3[k++] = (sum%10) + '0';
                         p=1;
                     }

                    hand = sum/10;
                    --j;
                }

            }
        }

            if(hand > 0)
                str3[k++] = '1';

            str3[k] = '\0';

            printf("%s\n", str3);

    }

    return 0;
}
