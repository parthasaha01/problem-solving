#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
        unsigned long int T, i=0, j, a, b, c, x, y, ara[3];

        scanf("%lu", &T);

        while(T--)
        {
                for(j=0; j<3; j++)
                    scanf("%lu", &ara[j]);

                sort(ara, ara+3);

                x = ara[2]*ara[2];
                y = (ara[0]*ara[0]) + (ara[1]*ara[1]);

                if( x == y )
                    printf("Case %lu: yes\n", ++i);
                else
                    printf("Case %lu: no\n", ++i);
        }

        return 0;
}
