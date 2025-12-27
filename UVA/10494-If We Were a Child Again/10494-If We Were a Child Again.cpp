#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long long rem, num, value, div, flag, L, i;
    char ch, str[1000];

    while(scanf("%s %c %lld", str, &ch, &num)==3)
    {
        L = strlen(str);

        //printf("%s %c %lld\n", str, ch, num);

        if(ch == '%')
        {
            rem=0;
            for(i=0; i<L; i++)
            {
                value = rem*10+(str[i]-48);
                rem = value%num;
            }

            printf("%lld\n", rem);
        }
        else
        {
            if(L==1 && str[0] == '0')
                printf("0\n");
            else
            {
                flag=0;
                rem=0;

                for(i=0; i<L; i++)
                {
                    value=rem*10+(str[i]-48);

                    div=value/num;

                    if(flag==0 && div>0)
                        flag=1;

                    if(flag)
                        printf("%lld",div);

                    rem=value%num;
                }
                printf("\n");
            }
        }
    }

    return 0;
}
