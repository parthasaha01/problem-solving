#include<stdio.h>
#include<string.h>
int main()
{
    long int T, N, i, j, L;
    char str[8005];

    scanf("%ld", &T);
    getchar();

    for(j=0; j<T; j++)
    {
        while(gets(str))
        {
            L = strlen(str);

            if(L == 0)
                break;

            for(i=0; i<L; i++)
            {
                switch(str[i])
                {
                    case '0':
                        str[i] = 'O';
                        break;

                    case '1':
                        str[i] = 'I';
                        break;

                    case '2':
                        str[i] = 'Z';
                        break;

                    case  '3':
                        str[i] = 'E';
                        break;

                    case  '4':
                        str[i] = 'A';
                        break;

                    case '5':
                        str[i] = 'S';
                        break;

                    case '6':
                        str[i] = 'G';
                        break;

                    case '7':
                        str[i] = 'T';
                        break;

                    case '8':
                        str[i] = 'B';
                        break;

                    case '9':
                        str[i] = 'P';

                }

            }
            puts(str);

        }

        if (j != T-1)
            printf("\n");

    }

    return 0;
}
