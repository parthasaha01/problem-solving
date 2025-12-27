#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main()
{
    long int N, i, j, sp, p=0;
    map<long int,long int>num;

    scanf("%ld", &N);

    sp = sqrt((double)N);

    for(i=3; i<=sp; i += 2)
    {
        if(num[i>>1] == 0)          // i>>1 means 2*i+1 that means odd number
        {
            for(j=i*i; j<=N; j += (i+i))
            {
                num[j>>1]=1;
            }
        }
    }

    if(N>1)
    {
        printf("2 ");
        ++p;
    }
    for(i=3; i<=N; i+=2)
    {
        if(num[i>>1] == 0)          // ( i >> 1) means (i/2)
        {
            ++p;
            printf("%ld ", i);
        }
    }


    printf("\n\nTotal prime is: %ld\n", p);

    return 0;
}
