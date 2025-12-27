#include<cstdio>
#include<cstring>
#include<cstdlib>
int main()
{
    int a, b, c, res=0;
    char ch, p, s[5];

    while(scanf("%d %c %d %c %s", &a, &ch, &b, &p, s)==5)
    {
        //printf("%d %d %d %s\n", a, b, c, ch);

        if(strcmp(s, "?"))
        {
            c=atoi(s);

            if(ch=='+')
            {
                if(a+b == c)
                    ++res;
            }
            else
            {
                if(a-b == c)
                    ++res;
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
