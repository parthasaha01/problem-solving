#include<stdio.h>
#include<string.h>
int main()
{
    long int L1, L, i, M=1;
    char word1[10005], word2[10005], word[10005];

    while(scanf("%s", word1))
    {

        if(!strcmp(word1,"E-N-D"))
            break;

        L1 = strlen(word1);
        L=0;

        for(i=0; i<L1; i++)
        {
            if(word1[i]>='a'&&word1[i]<='z' || word1[i]>='A'&&word1[i]<='Z' || word1[i]=='-')
            {
                if(word1[i] >= 'A' && word1[i] <= 'Z')
                    word1[i] += 32;

                word2[L] = word1[i];
                ++L;
            }
        }

        if(L > M)
        {
            M = L;
            strcpy(word, word2);
        }
    }

    puts(word);

    return 0;
}
