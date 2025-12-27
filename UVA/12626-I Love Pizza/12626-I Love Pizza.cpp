#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, L, x, Min;
    char str[1000];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(str);
        L=strlen(str);

        Min = 600;

        int ara[6] = {0};

        for(x=0; x<L; x++)
        {
            switch(str[x])
            {
                case 'A':
                    ++ara[0];
                    break;
                case 'R':
                    ++ara[1];
                    break;
                case 'G':
                    ++ara[2];
                    break;
                case 'M':
                    ++ara[3];
                    break;
                case 'I':
                    ++ara[4];
                    break;
                case 'T':
                    ++ara[5];
                    break;
            }
        }

        ara[0] /= 3;
        ara[1] /= 2;

        for(x=0; x<6; x++)
        {
            if(ara[x] < Min)
                Min=ara[x];
        }

        printf("%d\n", Min);
    }

    return 0;
}
