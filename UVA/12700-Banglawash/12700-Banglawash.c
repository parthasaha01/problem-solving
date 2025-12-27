#include<stdio.h>
#include<string.h>
int main()
{
    int T, N, bang, white, aband, draw, i, test=0;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &N);
        getchar();

        char str[N];

        gets(str);

        bang = white = draw = aband = 0;

        for(i=0; i<N; i++)
        {
            switch(str[i])
            {
                case 'B':
                    bang++;
                    break;
                case 'W':
                    white++;
                    break;
                case 'T':
                    draw++;
                    break;
                default:
                    aband++;
            }
        }
        if(aband == N)
            printf("Case %d: ABANDONED\n", ++test);
        else if((bang+aband) == N)
            printf("Case %d: BANGLAWASH\n", ++test);
        else if((white+aband) == N)
            printf("Case %d: WHITEWASH\n", ++test);
        else if(bang > white)
            printf("Case %d: BANGLADESH %d - %d\n", ++test, bang, white);
        else if(white > bang)
            printf("Case %d: WWW %d - %d\n", ++test, white, bang);
        else
            printf("Case %d: DRAW %d %d\n", ++test, bang, draw);

    }

    return 0;
}
