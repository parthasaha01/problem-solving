#include<stdio.h>
#include<string.h>
int main()
{
    char str1[50], str2[50];
    int i, length;

    while(gets(str1))
    {
        length = strlen(str1);

        for(i=0; i<length; i++)
        {
            if(str1[i] == '0')
                str2[i] = '0';

            else if(str1[i] == '1')
                str2[i] = '1';

            else if(str1[i]=='-')
                str2[i] = '-';

            else if(str1[i] >= 'A' && str1[i] <= 'C')
                str2[i] = '2';

            else if(str1[i] >= 'D' && str1[i] <= 'F')
                str2[i] = '3';

            else if(str1[i] >= 'G' && str1[i] <= 'I')
                str2[i] = '4';

            else if(str1[i] >= 'J' && str1[i] <= 'L')
                str2[i] = '5';

            else if(str1[i] >= 'M' && str1[i] <= 'O')
                str2[i] = '6';

            else if(str1[i] >= 'P' && str1[i] <= 'S')
                str2[i] = '7';

            else if(str1[i] >= 'T' && str1[i] <= 'V')
                str2[i] = '8';

            else if(str1[i] >= 'W' && str1[i] <= 'Z')
                str2[i] = '9';
        }

        str2[i] = '\0';
        puts(str2);
    }

    return 0;
}
