#include<stdio.h>
#include<string.h>
int main()
{
    int L, i, s;
    char str[25];

    while(gets(str))
    {
        L = strlen(str);
        s=0;

        for(i=0; i<L; i++)
        {
           switch(str[i])
           {
                case 'B': case 'F': case 'P': case 'V':
                    if(s != 1)
                        printf("1");
                    s=1;
                    break;
                case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
                    if( s != 2)
                        printf("2");
                    s=2;
                    break;
                case 'D': case 'T':
                    if(s != 3)
                        printf("3");
                    s=3;
                    break;
                case 'L':
                    if(s != 4)
                        printf("4");
                    s=4;
                    break;
                case 'M': case 'N':
                    if(s != 5)
                        printf("5");
                    s=5;
                    break;
                case 'R':
                    if(s != 6)
                        printf("6");
                    s=6;
                    break;
                default:
                    s=0;
           }
        }
        printf("\n");
    }

    return 0;
}

