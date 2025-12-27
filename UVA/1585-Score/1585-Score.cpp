#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, i, L, sum, m;
    char S[81];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(S);
        L = strlen(S);
        sum=0;
        m=1;

        for(i=0;i<L; i++)
        {
            if(S[i] == 'O')
            {
                sum += m++;
            }
            else
            {
                m=1;
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
