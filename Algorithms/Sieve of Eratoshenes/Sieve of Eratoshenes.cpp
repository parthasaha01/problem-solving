#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int main()
{
    long int N, i, j, sq, p=0;
    map<long int,long int>num;

    scanf("%ld", &N);

    sq = sqrt((double)N);

    for(i=3; i<=sq; i += 2)
    {
        if(num[i] == 0)
        {
            for(j=i*i; j<=N; j += (i+i))
            {
                num[j]=1;
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
        if(num[i] == 0)
        {
            ++p;
            printf("%ld ", i);
        }
    }

    printf("\n\nTotal prime is: %ld\n", p);

    return 0;
}
