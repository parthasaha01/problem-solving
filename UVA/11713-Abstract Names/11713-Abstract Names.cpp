#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int answer(void);
int main()
{
        long int T, L1, L2, i, result;


        scanf("%ld", &T);
        getchar();

        while(T--)
        {
            result = answer();

            if(result == 1)
                printf("Yes\n");
            else
                printf("No\n");

        }

        return 0;
}
int answer(void)
{
    long int L1, L2, i;
    char str1[100], str2[100];

        gets(str1);
        gets(str2);

        L1 = strlen(str1);
        L2 = strlen(str2);

            if(L1 == L2)
            {
                for(i=0; i<L1; i++)
                {
                    if(str1[i] == str2[i])
                    {
                        continue;
                    }
                    else if((str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' )  && (str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u' ))
                    {
                        continue;
                    }
                    else
                    {
                        return 0;
                    }
                }

                return 1;
            }
            else
                return 0;
}
