#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int minimum(int ara[], int N);
int main()
{
    int N, i, j, L, min_space, total_space, space, result;
    char str[50];

    while(scanf("%d", &N) == 1)
    {
        getchar();

        total_space = 0;

        if(N == 0)
            break;

        int ara[N];

        for(i=0; i<N; i++)
        {
            gets(str);
            L = strlen(str);
            space = 0;

            for(j=0; j<L; j++)
            {
                if(str[j] == ' ')
                {
                    ++space;
                    ++total_space;
                }
            }

            ara[i] = space;
        }

        min_space = minimum(ara, N);

        result = total_space - (N*min_space);

        printf("%d\n", result);
    }

    return 0;
}
int minimum(int ara[], int N)
{

    int j, temp, Min=0;

        for(j=Min+1; j<N; j++)
        {
            if(ara[Min] > ara[j])
            {
                temp = ara[Min];
                ara[Min] = ara[j];
                ara[j] = temp;
            }
        }

    //sort(ara, ara+N);

    return ara[0];
}
