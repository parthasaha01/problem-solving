#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int Max, i, T, test=1;
    char urls[10][120];
    int rels[10];


    scanf("%d", &T);
    getchar();

    while(T--)
    {
        Max=0;

        for(i=0; i<10; i++)
        {
            scanf("%s %d", urls[i], &rels[i]);

            Max = max(Max, rels[i]);
        }

        printf("Case #%d:\n", test++);

        for(i=0; i<10; i++)
        {
            if(Max == rels[i])
                printf("%s\n", urls[i]);
        }
    }

    return 0;
}
