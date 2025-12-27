#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int k, i, flag, L;
    char N[200], num[200], D;

    while(scanf("%c %s", &D, N))
    {
        getchar();

       if(D=='0' && !strcmp(N,"0"))
            break;

        L=strlen(N);
        flag=0;
        k=0;

        for(i=0; i<L; i++)
        {
            if(N[i] != D)
            {
                if(flag || N[i] != '0')
                {
                    num[k++]=N[i];
                    flag=1;
                }
            }
        }
        num[k]='\0';

        if(k)
            puts(num);
        else
            printf("0\n");
    }

    return 0;
}
