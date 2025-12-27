#include<stdio.h>
int main()
{
    char ch;
    int i, num=1;

    while(ch = getchar())
    {
        switch(ch)
        {
            case '"':
                switch(num)
                {
                    case 1:
                        printf("``");
                        num=2;
                        break;
                    default:
                        printf("''");
                        num = 1;
                }
                break;
            case EOF:
                    goto line;
                break;
            default:
                printf("%c",ch);

        }

    }
    line:

    return 0;
}
