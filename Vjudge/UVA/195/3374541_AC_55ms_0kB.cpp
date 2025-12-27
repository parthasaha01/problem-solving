#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int T, i, L, d, a[500];
    char word[500], M[1000];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(word);
        L=strlen(word);

        for(i=0; i<L; i++)
        {
            d=word[i];

            if(d>=65 && d<=90)              //  A=131, B=133, C=135, D=137......
                d = 2*d;
            else
                d = 131 + 2*(d-97);             // a=132, b=134, c=136, d=138....

            M[d] = word[i];
            a[i] = d;
        }

        sort(a, a+L);               // sort the array

        do                              //because at first it is already sorted
        {
            for(i=0; i<L; i++)
            {
                printf("%c", M[a[i]]);
            }
            printf("\n");
        }while(next_permutation(a, a+L));           // array must be sorted for output alphabetically ascending order
                                                                                    // not produce same word more than once
    }

    return 0;
}
