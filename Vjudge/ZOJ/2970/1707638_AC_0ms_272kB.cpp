#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long int T, N, i, value[3000];
    char str[20];

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        scanf("%s", str);

        scanf("%ld", &N);

        for(i=0; i<N; i++)
        {
            scanf("%ld", &value[i]);
        }

        sort(value,value+N);

        if(str[0] == 'F')
            printf("%ld\n", value[0]);
        else
            printf("%ld\n", value[N-1]);

    }

    return 0;
}