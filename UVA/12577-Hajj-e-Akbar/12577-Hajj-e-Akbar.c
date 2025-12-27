#include<stdio.h>
#include<string.h>
int main()
{
    int i=0;
    char str[100];

    while(gets(str))
    {
        ++i;

        if( strcmp(str, "*") == 0 )
            break;

        else if( strcmp(str, "Hajj") == 0 )
            printf("Case %d: Hajj-e-Akbar\n",i);

        else if( strcmp(str, "Umrah") == 0 )
            printf("Case %d: Hajj-e-Asghar\n",i);
    }

    return 0;
}
