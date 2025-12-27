#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, L, M, F, i;
    char str[200];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(str);
        L=strlen(str);

        if(L<4)
            printf("NO LOOP\n");
        else
        {
            M=F=0;
            for(i=0; i<L; i++)
            {
                if(str[i] == 'M')
                    ++M;
                else if(str[i] == 'F')
                    ++F;
            }

            if(M==F)
                printf("LOOP\n");
            else
                printf("NO LOOP\n");
        }
    }

    return 0;
}
