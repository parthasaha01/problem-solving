#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long int N, G, S, R, i, b[100000], points, k, diff;

    while(scanf("%ld %ld", &N, &G)==2)
    {
        points = k = 0;

        for(i=0; i<N; i++)
        {
            scanf("%ld %ld", &S, &R);
            diff=R-S;

            if(diff<0)
            {
                points += 3;
            }
            else
            {
                if(!diff)
                    points += 1;

                b[k++]=diff;
            }
        }

        sort(b, b+k);
        i=0;
        while(G>0 && i<k)
        {
            if(!b[i])
            {
                points += 2;
                G -= 1;
            }
            else
            {
                if(b[i] < G)
                {
                    points += 3;
                    G -= b[i]+1;
                }
                else if(b[i] == G)
                {
                    points += 1;
                    break;
                }
                else
                    break;
            }

            i++;
        }

        printf("%ld\n", points);
    }

    return 0;
}
