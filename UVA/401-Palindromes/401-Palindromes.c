#include<stdio.h>
#include<string.h>

int palindrome(char str[]);
int mirrored(char str[]);

int i, j, L, p, m;

int main()
{
    char str[20];

    while(gets(str))
    {
        L = strlen(str);
        p = palindrome(str);
        m = mirrored(str);


        if(p && m )
            printf("%s -- is a mirrored palindrome.", str);
        else if(p)
            printf("%s -- is a regular palindrome.", str);
        else if(m)
            printf("%s -- is a mirrored string.", str);
        else
            printf("%s -- is not a palindrome.", str);

        printf("\n\n");

    }

    return 0;
}
int palindrome(char str[])
{
    char str2[25];

    j=L-1;
    for(i=0; i<L; i++, j--)
    {
        str2[i] = str[j];
    }

    str2[i] = '\0';

    if(!strcmp(str, str2))
        return 1;
    else
        return 0;
}
int mirrored(char str[])
{
    char str2[25], str3[25];

    strcpy(str3,str);

    for(i=0; i<L; i++)
    {
        switch(str3[i])
        {
            case 'A':
                str3[i] = 'A';
                break;
            case 'E':
                str3[i] = '3';
                break;
            case 'H':
                str3[i] = 'H';
                break;
            case 'I':
                str3[i] = 'I';
                break;
            case 'J':
                str3[i] = 'L';
                break;
            case 'L':
                str3[i] = 'J';
                break;
            case 'M':
                str3[i] = 'M';
                break;
            case 'O':
                str3[i] = 'O';
                break;
            case 'S':
                str3[i] = '2';
                break;
            case 'T':
                str3[i] = 'T';
                break;
            case 'U':
                str3[i] = 'U';
                break;
            case 'V':
                str3[i] = 'V';
                break;
            case 'W':
                str3[i] = 'W';
                break;
            case 'X':
                str3[i] = 'X';
                break;
            case 'Y':
                str3[i] = 'Y';
                break;
            case 'Z':
                str3[i] = '5';
                break;
            case '1':
                str3[i] = '1';
                break;
            case '2':
                str3[i] = 'S';
                break;
            case '3':
                str3[i] = 'E';
                break;
            case '5':
                str3[i] = 'Z';
                break;
            case '8':
                str3[i] = '8';
                break;
            default :
                return 0;
        }
    }

    str3[i] = '\0';

    j= L-1;

    for(i=0; i<L; i++, j--)
    {
        str2[i] = str3[j];
    }
    str2[i] = '\0';

    if(!strcmp(str, str2))
        return 1;
    else
        return 0;

}
