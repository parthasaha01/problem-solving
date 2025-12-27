#include <cctype>
#include <cstdio>

int main()
{
    char line[4096];
    long long T, M, MB, R, maxv, n, nb, r, minv;

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        fgets(line, 4096, stdin);

        R=1;
        M = MB = 0;

        n = 1;
        r = nb = 0;

        for(char *p = line; *p; ++p)
        {
            if(isdigit(*p))
            {
                MB = MB * 10 + *p - '0';
                nb = nb * 10 + *p - '0';
            }
            else
            {
                if(*p == '*')
                {
                    R *= (M + MB);
                    M = 0;

                    n = n*nb;
                }
                else if(*p == '+')
                {
                    M += MB;

                    r += n * nb;
                    n = 1;
                }
                else
                {
                    R *= (M + MB);

                    r += n * nb;
                }

                MB = 0;
                nb = 0;
            }
        }

        maxv = R;
        minv = r;

        printf("The maximum and minimum are %lld and %lld.\n", maxv, minv);
    }
    return 0;
}
