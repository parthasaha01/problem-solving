#include<cstdio>
#include<iostream>
#include<cstring>
int main()
{
    int T, i, N, pos, num, L, p, j;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d", &N);
        getchar();

        char str[110][20];
        int b[110] = {0};
        pos=0;

        for(i=0; i<N; i++)
        {
            gets(str[i]);

            if(str[i][0] == 'L')
            {
                --pos;
                b[i]=1;
            }
            else if(str[i][0] == 'R')
            {
                ++pos;
                b[i]=2;
            }
            else
            {
                L=strlen(str[i]);
                num=0;
                p=1;

                for(j=L-1; str[i][j] != ' '; j--)
                {
                    num = ((str[i][j]-'0')*p)+num;
                    p *= 10;
                }
                num -= 1;

                if(str[num][0] == 'L')
                {
                    --pos;
                    b[i]=1;
                }
                else if(str[num][0] == 'R')
                {
                    ++pos;
                    b[i]=2;
                }
                else
                {
                    if(b[num] == 1)
                    {
                        --pos;
                        b[i]=1;
                    }
                    else if(b[num] == 2)
                    {
                        ++pos;
                        b[i]=2;
                    }
                }
            }
        }

        printf("%d\n", pos);
    }

    return 0;
}
