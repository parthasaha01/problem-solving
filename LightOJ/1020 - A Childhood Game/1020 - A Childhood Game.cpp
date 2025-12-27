#include<bits/stdc++.h>
int main()
{
    long int T,n,test;
    char name[10];

    scanf("%ld",&T);

    for(test=1; test<=T; test++)
    {
        scanf("%ld %s",&n,name);

        if(!strcmp(name,"Alice"))
        {
            if((n%3)==1)
            {
                printf("Case %ld: Bob\n",test);
                continue;
            }
            else
            {
                printf("Case %ld: Alice\n",test);
                continue;
            }
        }
        else
        {
            if((n%3)==0)
            {
                printf("Case %ld: Alice\n",test);
                continue;
            }
            else
            {
                printf("Case %ld: Bob\n",test);
                continue;
            }
        }
    }

    return 0;

}

