#include<stdio.h>
#include<string.h>
int main()
{
    long int L1, L=1, i, c;
    char word1[1000005], word[1000005];

    while(scanf("%s", word1))
    {

        if(!strcmp(word1,"E-N-D"))
            break;

        L1 = strlen(word1);
        c=0;

        for(i=0; i<L1; i++)
        {
            if(word1[i]>='a'&&word1[i]<='z' || word1[i]>='A'&&word1[i]<='Z' || word1[i]=='-')
                continue;
            else
                ++c;
        }

        L1 = L1-c;

        if(L1 > L)
        {
            L = L1;
            strcpy(word, word1);
        }
    }

    L1 = strlen(word);

    for(i=0; i<L1; i++)
    {
        if(word[i] >='a' && word[i] <= 'z' || word[i] == '-')
            printf("%c", word[i]);
        else if(word[i] >='A' && word[i] <= 'Z')
            printf("%c",word[i]+32);
    }

    printf("\n");

    return 0;
}
