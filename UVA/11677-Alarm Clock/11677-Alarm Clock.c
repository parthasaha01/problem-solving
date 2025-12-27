#include<stdio.h>
int main()
{
    long int H1,M1,H2,M2,T1,T2,M;

    while(scanf("%ld %ld %ld %ld",&H1,&M1,&H2,&M2)==4 && (H1!=0 || M1!=0 || H2!=0 || M2!=0))
    {
        if(H1==0)
            H1=24;
        if(H2==0)
            H2=24;

        T1=(H1*60)+M1;
        T2=(H2*60)+M2;

        if(T1<=T2)
        {
            M=T2-T1;
        }
        else
        {
            M=(1440+T2)-T1;
        }

        printf("%ld\n",M);
    }

    return 0;
}
