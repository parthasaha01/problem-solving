
#include<stdio.h>
#include<string.h>
int main()
{
    int L, i, k, j;
    char str[100000];

    while(gets(str))
    {
        L = strlen(str);
        j=0;

        for(i=0; i<L; i++)
        {
            switch(str[i])
            {
                case ' ':
                    printf(" ");
                    break;
                case 'e' : case 'E':
                    printf("q");
                    break;
                case 'r': case 'R':
                    printf("w");
                    break;
                case 't': case 'T':
                    printf("e");
                    break;
                case 'y': case 'Y':
                    printf("r");
                    break;
                case 'u': case 'U':
                    printf("t");
                    break;
                case 'i': case 'I':
                    printf("y");
                    break;
                case 'o': case 'O':
                    printf("u");
                    break;
                case 'p': case 'P':
                    printf("i");
                    break;
                case '[':
                    printf("o");
                    break;
                case ']':
                    printf("p");
                    break;
                case 'd': case 'D':
                    printf("a");
                    break;
                case 'f': case 'F':
                    printf("s");
                    break;
                case 'g': case 'G':
                    printf("d");
                    break;
                case 'h': case 'H':
                    printf("f");
                    break;
                case 'j': case 'J':
                    printf("g");
                    break;
                case 'k': case 'K':
                    printf("h");
                    break;
                case 'l': case 'L':
                    printf("j");
                    break;
                case ';':
                    printf("k");
                    break;
                case 'c': case 'C':
                    printf("z");
                    break;
                case 'v': case 'V':
                    printf("x");
                    break;
                case 'b': case 'B':
                    printf("c");
                    break;
                case 'n': case 'N':
                    printf("v");
                    break;
                case 'm': case 'M':
                    printf("b");
                    break;
                case ',':
                    printf("n");
                    break;
                case '.':
                    printf("m");
                    break;
                default :
                    printf("l");
            }
        }
        printf("\n");
    }

    return 0;
}
