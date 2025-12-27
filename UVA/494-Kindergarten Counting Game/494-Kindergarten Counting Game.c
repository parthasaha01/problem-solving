#include<stdio.h>
#include<string.h>
int main()
{
    long int i, word;
    char str[2000];

    while(gets(str))
    {
        word=0;

        for(i=0; str[i]; i++)
        {
            if(((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')) && !((str[i+1]>='A' && str[i+1]<='Z') || (str[i+1]>='a' && str[i+1]<='z')))
            {
                ++word;
            }
        }

        printf("%ld\n", word);
    }

    return 0;
}
