#include<stdio.h>
#include<string.h>
int main()
{
    long int i=0, length;
    char str[20];

    while(gets(str))
    {
        length = strlen(str);


        if(length==1 && str[0] == '#')
            break;

        if(strcmp(str, "HELLO") == 0)
            printf("Case %ld: ENGLISH\n", ++i);

        else if(strcmp(str, "HOLA") == 0)
            printf("Case %ld: SPANISH\n", ++i);

        else if(strcmp(str, "HALLO") == 0)
            printf("Case %ld: GERMAN\n", ++i);

        else if(strcmp(str, "BONJOUR") == 0)
            printf("Case %ld: FRENCH\n", ++i);

        else if(strcmp(str, "CIAO") == 0)
            printf("Case %ld: ITALIAN\n", ++i);

        else if(strcmp(str, "ZDRAVSTVUJTE") == 0)
            printf("Case %ld: RUSSIAN\n", ++i);

        else
            printf("Case %ld: UNKNOWN\n", ++i);

    }

    return 0;
}
