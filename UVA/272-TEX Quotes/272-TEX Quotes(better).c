#include<stdio.h>
#include<string.h>
int main()
{
    char ch;
    int i, num=1;

    while(ch = getchar())
    {
        if(ch == EOF)
            break;

        else if(ch == '"')
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
