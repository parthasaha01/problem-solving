#include<stdio.h>
#include<string.h>
int main()
{
    char ch;
    int num=1;

    while(scanf("%c", &ch) == 1)
    {

        if(ch == '"')
        {
            if(num == 1)
            {
                printf("``");
                num=2;
            }
            else
            {
                printf("''");
                num = 1;
            }
        }
        else
            printf("%c",ch);
    }

    return 0;

}
