#include<stdio.h>
#include<string.h>
int balance(void);
int main()
{
    int T, result;

    scanf("%ld", &T);
    getchar();

    while(T--)
    {
        result = balance();

        if(result)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
int balance(void)
{
    int A1, A2, B1, B2, L, i, M;
    int f1, f2, p;
    char str[130];

        gets(str);
        L = strlen(str);

        A1=A2=B1=B2;

        if(str[0] == '(')
            p=1;
        else
            p=2;

        f1=f2=0;

        for(i=0; i<L; i++)
        {
            if( str[i] == '(' )
            {
                ++A1;
                f1=1;

                if(f2==1)
                    p=2;
            }
            else if( str[i] == ')' )
            {
                ++A2;

                if(A2>A1)
                    return 0;

                f1=0;

                if(p==1 && f2 != 0)
                    return 0;
            }
            else if( str[i] == '[' )
            {
                ++B1;
                f2=1;

                if(f1==1)
                    p=1;
            }
            else
            {
                ++B2;

                if(B2>B1)
                    return 0;

                    f2 = 0;

                if(p==2 && f1 != 0)
                    return 0;
            }
        }

        if(A1==A2 && B1==B2)
            return 1;
        else
            return 0;
}
