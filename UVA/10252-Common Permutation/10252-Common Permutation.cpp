#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char str1[1005], str2[1005], str3[1005], str4[1005], str5[1005], str6[1005];
    int i, j, k, m, n, p, x, y, L1, L2, L3, L4, L5;

    while(gets(str1) && gets(str2))
    {
        L1=strlen(str1);
        L2=strlen(str2);

        sort(str1, str1+L1);
        sort(str2, str2+L2);

        m=0;

        for(i=0; i<L1; i++)
        {
            if(str1[i] != str1[i+1])
            {
                str3[m] = str1[i];
                ++m;
            }
        }
        str3[m] = '\0';

        n=0;

        for(i=0; i<L2; i++)
        {
            if(str2[i] != str2[i+1])
            {
                str4[n] = str2[i];
                ++n;
            }
        }
        str4[n] = '\0';

        L3 = strlen(str3);
        L4 = strlen(str4);

        k=0;

        for(i=0; i<L3; i++)
        {
            for(j=0; j<L4; j++)
            {
                if(str3[i] == str4[j])
                {
                    str5[k] = str3[i];
                    ++k;
                    break;
                }
            }
        }
        str5[k] = '\0';
        L5 = strlen(str5);

        p=0;

        for(i=0; i<L5; i++)
        {
            x=0;
            y=0;

            for(j=0; j<L1; j++)
            {
                if(str5[i] == str1[j])
                    ++x;
            }
            for(j=0; j<L2; j++)
            {
                if(str5[i] == str2[j])
                    ++y;
            }

            if(x<y)
            {
                for(j=0; j<x; j++)
                {
                    str6[p] = str5[i];
                    ++p;
                }
            }
            else
            {
                for(j=0; j<y; j++)
                {
                    str6[p] = str5[i];
                    ++p;
                }
            }
        }

        str6[p] = '\0';
        puts(str6);

    }

    return 0;
}
