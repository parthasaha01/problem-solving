#include<bits/stdc++.h>
using namespace std;
int ar[100005];
int main()
{
    int n,total,half,start,a,b,k,bt;

    while(scanf("%d",&n)==1)
    {
        total=0;
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
            total+=ar[i];
        }

        half=total/2;
        start=0;
        k=1;
        b=0;
        a=0;
        for(int i=0; i<n; i++)
        {
            if(start+ar[i]>half)
            {
                bt = total-start-ar[i];
                if(start<=bt)
                {
                    a=i+1;
                    break;
                }
                else
                {
                    a=i;
                    break;
                }
            }
            else
            {
                start += ar[i];
            }
        }

        b=n-a;

        cout << a << " " << b << endl;

    }

    return 0;
}
