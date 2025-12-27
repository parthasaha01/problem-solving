#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int counter, i;
    double sum;
    char *p;
    char input[1000000];

    while (gets(input))
    {
        if (!strcmp(input,"*"))
            break;


        counter=0;

        p = strtok(input, "/");

        while (p != '\0')
        {
            sum = 0.0;

            for (i=0; p[i]>='A' &&  p[i]<='Z' ; i++)
            {
                if (p[i]=='W') sum += 1.0;
                else if (p[i]=='H') sum += 0.5;
                else if (p[i]=='Q') sum += 0.25;
                else if (p[i]=='E') sum += 0.125;
                else if (p[i]=='S') sum += 0.0625;
                else if (p[i]=='T') sum += 0.03125;
                else if (p[i]=='X') sum += 0.015625;
            }
            if (sum == 1.0)
                ++counter;

            p = strtok('\0', "/");
        }
        printf("%ld\n",counter);
    }
    return 0;
}
