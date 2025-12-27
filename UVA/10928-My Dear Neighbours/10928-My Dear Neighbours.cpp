#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long int T, i, M, Min, P;
    char c;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &P);

        Min = P;

         long int neigh[1005] = {0};

        for(i=1; i<=P; i++)
        {
            while(1)
            {
                scanf("%ld", &M);

                ++neigh[i];

                c = getchar();

                if(c == '\n')
                    break;

            }


            if(Min > neigh[i])
                Min = neigh[i];
        }

        int space = 0;

        for(i=1; i<=P; i++)
        {
            if(Min == neigh[i])
            {
                if(space == 0)
                {
                    space = 1;
                    printf("%ld", i);
                }
                else
                    printf(" %ld", i);

            }

        }

        printf("\n");
    }

    return 0;
}
