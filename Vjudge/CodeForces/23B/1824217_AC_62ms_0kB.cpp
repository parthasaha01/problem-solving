#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long int T, N;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);

        if(N < 3)
            printf("0\n");
        else
            printf("%ld\n", N-2);
    }

    return 0;
}
