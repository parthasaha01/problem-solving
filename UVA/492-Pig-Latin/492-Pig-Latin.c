#include<stdio.h>
#include<string.h>
int main()
{
    long int i=0, c, x=0;
    char ch, con;

    while(ch=getchar())
    {
        if(ch == EOF)
            break;

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if( x == 0 && i == 0 && !(ch=='A' || ch=='a' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O'|| ch=='o' || ch=='U' || ch =='u'))
            {
                con = ch;
                x=1;
                c=1;
                i=1;
            }
            else
            {
                printf("%c", ch);
                c=1;
                x=1;
            }
        }
        else
        {
            if(i==1)
            {
                printf("%c",con);
            }
            if(c==1)
            {
                printf("ay");
                c = 0;
            }
            printf("%c", ch);
            x=0;
            i=0;


        }

    }

    return 0;
}
