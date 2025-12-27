#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int answer(int, int, int, int );
int main()
{
    int h1,h2,h3,h4,m1,m2,m3,m4, T, A1, A2, B1, B2, result, test=0;
    char c1, c2, c3, c4;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%d %c %d %d %c %d", &h1, &c1, &m1, &h2, &c2, &m2);
        scanf("%d %c %d %d %c %d", &h3, &c3, &m3, &h4, &c4, &m4);

        //printf("%d    %d    %d   %d   %d   %d   %d    %d\n", h1, m1, h2, m2, h3, m3, h4, m4);

        A1 = (h1*60) + m1;
        A2 = (h2*60) + m2;

        B1 = (h3*60) + m3;
        B2 = (h4*60) + m4;

       // printf("%d    %d   %d    %d\n", A1, A2, B1, B2);

        result = answer(A1,A2,B1,B2);

        if(result == 1)
            printf("Case %d: Hits Meeting\n", ++test);
        else
            printf("Case %d: Mrs Meeting\n", ++test);

    }
}
int answer(int A1, int A2, int B1, int B2)
{
    if(B1 < A1 && B2 < A1)
        return 1;
    else if(B1 > A2)
        return 1;
    else
        return 0;
}
