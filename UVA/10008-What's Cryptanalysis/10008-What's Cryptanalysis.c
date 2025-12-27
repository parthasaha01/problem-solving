#include<stdio.h>
#include<string.h>
int result[130];
int main()
{
    int T, i, Max, p, L;
    char str[1000];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(str);
        L = strlen(str);
        Max=0;

        for(i=0; i<L; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                p=str[i];

                result[p]++;

                if(result[str[i]]> Max)
                    Max=result[p];
            }
            else if(str[i]>='a' && str[i]<='z')
            {
                p=str[i]-32;

                result[p]++;

                if(result[p] > Max)
                    Max = result[p];
            }
        }
    }

    for(i=Max; i>0; i--)
    {
        for(p=65; p<91; p++)
        {
            if(result[p] ==  i)
                printf("%c %d\n", p, i);
        }
    }

    return 0;
}
