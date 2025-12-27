#include<bits/stdc++.h>
using namespace std;
#define N 1050
#define sqN 32
int num[1200];
void seive()
{
    int i,j;

    for(i=3; i<=sqN; i+=2)
    {
        if(num[i]==0)
        {
            for(j=i*i; j<=N; j+=(i+i))
            {
                num[j]=1;
            }
        }
    }
}
int main()
{
    seive();

    int L,i,sum;
    char str[25];

    while(gets(str))
    {
        L=strlen(str);
        sum=0;

        for(i=0; i<L; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                sum += (str[i] - 'a' + 1);
            else
                sum += (str[i] - 'A' + 27);
        }

        //printf("%d %d",sum,num[sum]);

        if(sum==1 || sum==2)
        {
            printf("It is a prime word.\n");
        }
        else if((sum%2)==0)
        {
            printf("It is not a prime word.\n");
        }
        else if(num[sum]==0)//prime
        {
            printf("It is a prime word.\n",sum);
        }
        else
        {
            printf("It is not a prime word.\n");
        }

    }

    return 0;
}
