#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int carry, i, j, L1, L2;
    char a[500], b[500], X[500], Y[500];

    while(gets(a))
    {
        gets(b);

        L1 = strlen(a);
        L2=strlen(b);
        int Z[1000] = {0};

        for(i=0, j=L1-1; i<L1; i++)
            X[i] = a[j--];       // reverse a
        X[i] = '\0';

        for(i=0, j=L2-1; i<L2; i++)
            Y[i] = b[j--];      // reverse b
        Y[i] = '\0';

        for(i = 0; i<L1; i++)
        {
            carry = 0;
            for(j = 0; j<L2; j++)
            {
                Z[i + j] += (X[i] - '0') * (Y[j] - '0') + carry;
                carry = Z[i + j] / 10;
                Z[i + j] %= 10;
            }
            Z[i + j] += carry;
        }

        for(i=i+j-1; i>=0; i--)
            if(Z[i] != 0)
                break;

        if(i<0)
        {
            printf("0");
        }
        else
        {
            while(i>=0)
                printf("%d", Z[i--]);
        }

        printf("\n");

    }

    return 0;
}
