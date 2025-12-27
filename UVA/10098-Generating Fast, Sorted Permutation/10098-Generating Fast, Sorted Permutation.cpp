#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int T, i, L;
    char word[15];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(word);
        L=strlen(word);

        sort(word, word+L);

        do
        {
            puts(word);
        }while(next_permutation(word, word+L));

        putchar('\n');
    }

    return 0;
}
