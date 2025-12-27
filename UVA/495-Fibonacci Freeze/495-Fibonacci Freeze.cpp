#include<iostream>
#include<cstdio>
#define LIM 5001
#define LEN 1050
int fbn[LIM][LEN];
using namespace std;
void fibonacci(void)
{
    int x, y;

    fbn[0][0]=0;
    fbn[1][0]=fbn[2][0]=1;

    for(x=3; x<LIM; x++)
    {
        for(y=0; y<LEN; y++)
        {
            fbn[x][y] += fbn[x-2][y]+fbn[x-1][y];

            if(fbn[x][y] > 9)
            {
                fbn[x][y+1] += fbn[x][y]/10;
                fbn[x][y] %= 10;
            }
        }
    }
}
int main()
{
    int n, x, y;

    fibonacci();

    while(scanf("%d", &n)==1)
    {

        for(y=LEN-1; y>0; y--)
        {
            if(fbn[n][y] != 0)
                break;
        }

        printf("The Fibonacci number for %d is ",n);

        for(; y>=0; y--)
            printf("%d", fbn[n][y]);

        printf("\n");
    }

    return 0;
}
