#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, L, i, k, n, flag;
    double mass, m;
    char str[200];

    scanf("%d", &T);
    getchar();

    while(T--)
    {
        gets(str);
        L=strlen(str);
        flag=0;
        k=1;
        mass=0.0;

        for(i=0; i<L; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                if(flag)
                {
                    mass += (m*k);
                }

                switch(str[i])
                {
                    case 'H':
                        m = 1.008;
                        break;
                    case 'C':
                        m = 12.01;
                        break;
                    case 'N':
                        m = 14.01;
                        break;
                    case 'O':
                        m = 16.00;
                        break;
                }
                k=1;
                flag=1;
                n=0;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                k = n+(str[i]-'0');
                n=k*10;
            }
        }

        mass += (m*k);

        printf("%.3lf\n", mass);
    }

    return 0;
}
