#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[100000], t[100000], ch;
    long int Ls, Lt, i, flag, p;

    while(scanf("%s %s", s, t)==2)
    {
        Ls=strlen(s);
        Lt=strlen(t);

        flag=p=0;
        ch=s[p];

        for(i=0; i<Lt; i++)
        {
            if(t[i] ==   ch)
            {
                ++p;
                ch=s[p];

                if(p == Ls)
                {
                    flag=1;
                    break;
                }
            }
        }

        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
