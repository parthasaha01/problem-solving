#include<stdio.h>
#include<string.h>
int main()
{
    long int T,i,j,L,press;
    char str[105];

    scanf("%ld",&T);
    getchar();
    for(j=1; j<=T; j++)
    {
        gets(str);
        L=strlen(str);
        press=0;

        for(i=0; i<L; i++)
        {
            if(str[i]==' ' || str[i]=='a' || str[i]=='d' || str[i]=='g' || str[i]=='j' || str[i]=='m' || str[i]=='p' || str[i]=='t' || str[i]=='w')
            {
                press += 1;
            }
            else if(str[i]=='b' || str[i]=='e' || str[i]=='h' || str[i]=='k' || str[i]=='n' || str[i]=='q' || str[i]=='u' || str[i]=='x')
            {
                press += 2;
            }
            else if(str[i]=='c' || str[i]=='f' || str[i]=='i' || str[i]=='l' || str[i]=='o' || str[i]=='r' || str[i]=='v' || str[i]=='y')
            {
                press += 3;
            }
            else if(str[i]=='s' || str[i]=='z')
            {
                press += 4;
            }
        }
        printf("Case #%ld: %ld\n",j,press);
    }

    return 0;
}
