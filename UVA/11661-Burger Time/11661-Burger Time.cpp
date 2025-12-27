#include<iostream>
#include<cstdio>
#include<cstring>
int main()
{
    long int L, i, Min, dis, r, d, m, n;
    char str[2000005];

    while(scanf("%ld", &L) && L)
    {
        getchar();
        gets(str);
        m=n=0;
        Min=2000005;

        for(i=0; i<L; i++)
        {
            if(str[i] == 'R')
            {
                if(n)
                {
                    dis=i-d;

                    if(dis<Min)
                        Min=dis;
                }
                m=1;
                r=i;
            }
            else if(str[i] == 'D')
            {
                if(m)
                {
                    dis = i-r;

                    if(dis<Min)
                        Min=dis;
                }
                n=1;
                d=i;
            }
            else if(str[i] == 'Z')
            {
                Min=0;
                break;
            }
        }

        printf("%ld\n", Min);
    }

    return 0;
}
