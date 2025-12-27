#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
int  main()
{
    int T, L, k, p, i, j, num, test=1;
    char a[500], b[500], ch;

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(a);
        L=strlen(a);
        ch=a[0];
        num=k=0;

        for(i=1; i<L; i++)
        {
            if(a[i] >= 'A' && a[i] <= 'Z')
            {
                for(j=0; j<num; j++)
                {
                    b[k++] = ch;
                }
                ch = a[i];
                num=0;
            }
            else
            {
                num = (num*10)+(a[i]-'0');
            }
        }
        for(j=0; j<num; j++)
        {
            b[k++] = ch;
        }

        b[k]='\0';

        printf("Case %d: %s\n", test++, b);

    }

    return 0;
}
