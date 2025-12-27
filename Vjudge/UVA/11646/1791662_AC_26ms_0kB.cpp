#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#define pi 3.1415926535897932384626433832795
using namespace std;
int main()
{
  char ch;
  int i,t=1;
  double a,x,y,ans,s,l;

  while(scanf("%lf %c %lf", &x, &ch, &y) == 3)
  {
    s=0.0;
    l=400.0;
      for(i=0;i<100;i++)
        {
            a=(s+l)/2;
            ans=a*(sqrt(x*x+y*y)*acos((x*x-y*y)/(x*x+y*y))+2*x);
            if(ans>400.00)
            l=a;
            else
            s=a;
        }

    cout<<"Case "<<t<<": "<<setprecision(13)<<a*x<<" "<<setprecision(12)<<a*y<<endl;
    t++;
  }

  return 0;
}