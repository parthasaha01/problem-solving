#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    long int Ln, i, k, num1, num2, Min, div;
    char num[20], big[20];

    while(gets(num))
    {
        Ln = strlen(num);
        k=0;

        sort(num, num+Ln);

        for(i=Ln-1; i>=0; i--)
        {
            big[k++] = num[i];
        }
        big[k]= '\0';

        i=0;

        while(i<Ln)
        {
            if(num[i] != '0')
            {
                if(i>0)
                {
                    num[0]=num[i];
                    num[i]='0';
                }
                break;
            }
            i++;
        }

        //puts(big);
        //puts(num);

        num1=atol(big);
        num2=atol(num);

        //printf("%ld   %ld\n", num1, num2);

        Min=num1-num2;

        div=Min/9;

        printf("%ld - %ld = %ld = 9 * %ld\n", num1, num2, Min, div);
    }
}
