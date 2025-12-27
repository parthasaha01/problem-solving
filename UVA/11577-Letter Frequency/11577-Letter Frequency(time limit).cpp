#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int T, Max, i, L;
    char b[205];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        int a[130]={0};
        Max=0;

        gets(b);
        L=strlen(b);

            for(i=0; i<L; i++)
            {
                if(isalpha(b[i]))
                {
                    b[i]=tolower(b[i]);
                    a[b[i]]++;

                    if(a[b[i]] > Max)
                        Max=a[b[i]];
                }
            }

        for(i=97; i<=122; i++)
        {
            if(a[i] == Max)
            {
                printf("%c", i);
            }
        }
        printf("\n");
    }

    return 0;
}
