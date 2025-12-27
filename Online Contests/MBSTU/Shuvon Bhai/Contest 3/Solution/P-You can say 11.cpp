#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long int i, length, num, rem;
    char str[1005];

    while(gets(str))
    {
        length = strlen(str);
        num = 0;


        if(length ==1 && str[0] == '0')
            break;

        for(i=0; i<length; i++)
        {
            num += str[i] - '0';

            rem = num%11;
            num = (rem*10);
        }

        if(rem == 0)
            printf("%s is a multiple of 11.\n", str);
        else
            printf("%s is not a multiple of 11.\n", str);
    }

    return 0;
}

