#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x, int y){
    return x>y;
}
int main()
{
    int n,n1,n2;
    while(cin>>n>>n1>>n2)
    {
       for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
       }

       sort(a,a+n,cmp);

       double sum1=0.0;

       for(int i=0; i<n1; i++){
            sum1+=a[i];
       }
       double sum2=0.0;
       for(int i=n1; i<n1+n2; i++){
            sum2+=a[i];
       }

       double avg1 = (sum1/(double)n1) + (sum2/(double)n2);

       sum1=0.0;

       for(int i=0; i<n2; i++){
            sum1+=a[i];
       }
       sum2=0.0;
       for(int i=n2; i<n2+n1; i++){
            sum2+=a[i];
       }

       double avg2 = (sum1/(double)n2) + (sum2/(double)n1);

       double avg=0.0;

       if(avg1>avg2) avg = avg1;
       else avg = avg2;

       printf("%.8lf\n",avg);
    }

    return 0;
}

