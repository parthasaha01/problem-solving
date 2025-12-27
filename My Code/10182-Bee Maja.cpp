#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int s;

    while(scanf("%ld",&s)==1)
    {
        if(s==1){
            printf("0 0\n");
            continue;
        }

        long int s1,s2;
        s1=s/3;
        s1=sqrt(s1);

        long int n1,n2,n;
        n1=s1-1;
        n2=s1;
        while(1)
        {
            if(s>(3*n1*(n1+1)+1)&& s<=(3*n2*(n2+1)+1)){
                n=n2;
                break;
            }
            else{
                n1++;
                n2++;
            }
        }

        long int sn,sn1,sn2,sn3,sn4,sn5,sn6;
        sn=3*n*(n+1)+1;
        sn1=sn-n;
        sn2=sn-2*n;
        sn3=sn-3*n;
        sn4=sn-4*n;
        sn5=sn-5*n;
        sn6=sn-6*n;

        long int x,y;

        if(s>=sn1){
            x=n;
            y=s-sn;
        }
        else if(s>=sn2){
            x=s-sn2;
            y=-n;
        }
        else if(s>=sn3){
            x=s-sn2;
            y=sn3-s;
        }
        else if(s>=sn4){
            x=-n;
            y=sn3-s;
        }
        else if(s>=sn5){
            x=sn5-s;
            y=n;
        }
        else{
            x=sn5-s;
            y=s-sn6;
        }


        printf("%ld %ld\n",x,y);
    }

    return 0;
}
