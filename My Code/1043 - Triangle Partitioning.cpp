#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    double high,low,mid,S,S1,AB,AC,BC,R,ABC,ADE,BDEC,r,DE,AD,AE,res;

    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&R);
        high=AB;
        low=0;
        res=0;
        S=(AB+AC+BC)/2.0;
        ABC=sqrt(S*(S-AB)*(S-AC)*(S-BC));
        while(high-low>0.0000001)
        {
            mid=(high+low)/2.0;
            AD=mid;
            AE=(AD*AC)/AB;
            DE=(AD*BC)/AB;
            S1=(AD+AE+DE)/2.0;
            ADE=sqrt(S1*(S1-AD)*(S1-AE)*(S1-DE));
            BDEC=ABC-ADE;
            r=ADE/BDEC;
            if(r<R){
                low=mid;
            }
            else if(r>R){
                high=mid;
            }
        }
        res=AD;

        printf("Case %d: %0.9lf\n",test,res);
    }

    return 0;
}
