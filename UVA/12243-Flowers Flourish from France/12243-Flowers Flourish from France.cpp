#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int tautogram(char str[])
{
    int L, i;
    char ch;

    L = strlen(str);
    ch = tolower(str[0]);

    for(i=1; i<L-1; i++)
    {
        if(str[i]== ' ')
        {
            str[i+1] = tolower(str[i+1]);

            if(ch != str[i+1])
                return 0;
        }
    }

    return 1;
}
int main()
{
    int result;
    char str[2000];

    while(gets(str))
    {
        if(str[0] == '*')
            break;

        result=tautogram(str);

        if(result)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
