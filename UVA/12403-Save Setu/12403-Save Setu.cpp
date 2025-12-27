#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long int num, sum=0, T;
    char str[10];

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        scanf("%s", str);

        if(str[0] == 'd')
        {
            scanf("%ld", &num);
            sum += num;
        }
        else
        {
            printf("%ld\n", sum);
        }
    }

    return 0;
}
