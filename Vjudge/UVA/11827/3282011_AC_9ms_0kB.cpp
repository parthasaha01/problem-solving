#include<cstdio>
#include<cstring>
using namespace std;
int GCD(int a, int b)
{
    if(b)
        return GCD(b, a%b);

    return a;
}
int main()
{
    long int N, num[100], i, Max, j, M, temp, gcd;
    char str[100];

    scanf("%ld", &N);
    getchar();

    while(N--)
    {

        gets(str);

        i=j=0;

        while(str[i])
        {
            num[j]=0;

            while(str[i] && str[i] != ' ')
                num[j] = (num[j]*10) + (str[i++]-'0');

            while(str[i] == ' ')
                i++;

            j++;
        }

        M = j;
        Max=1;

        for(i=0; i<M-1; i++)
        {
            for(j=i+1; j<M; j++)
            {
                gcd=GCD(num[i], num[j]);

                if(gcd>Max)
                    Max = gcd;
            }
        }

        printf("%ld\n", Max);
    }

    return 0;
}
