#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int T, N, D, i, test=1, ara[110], res;
    char s[110][25], str[110];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &N);
        getchar();
        res=0;

        for(i=0; i<N; i++)
        {
            scanf("%s %d", s[i], &ara[i]);
        }

        scanf("%d", &D);
        getchar();

        gets(str);

        for(i=0; i<N; i++)
        {
            if(!strcmp(str,s[i]))
            {
                if(ara[i] <= D)
                    res=1;
                else if(ara[i] <= D+5)
                    res=2;

                break;
            }
        }

        if(res == 1)
            printf("Case %d: Yesss\n", test++);
        else if(res == 2)
            printf("Case %d: Late\n", test++);
        else
            printf("Case %d: Do your own homework!\n", test++);
    }

    return 0;
}
