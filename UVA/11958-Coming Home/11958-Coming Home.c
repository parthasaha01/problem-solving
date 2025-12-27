#include<stdio.h>
int main()
{
    long int T, K, Q, HH, MM, hh, mm, test=1, Min, present, bus, time;
    char ch;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld %ld %c %ld", &K, &HH, &ch, &MM);

        present=(HH*60)+MM;
        Min=10000;

        while(K--)
        {
            scanf("%ld %c %ld %ld", &hh, &ch, &mm, &Q);

            bus = (hh*60)+mm;

            if(bus < present)
                bus = ((hh+24)*60)+mm;

            time = (bus+Q) - present;

            if(time < Min)
                Min = time;
        }

        printf("Case %ld: %ld\n", test++, Min);
    }

    return 0;
}
