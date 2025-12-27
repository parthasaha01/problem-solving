#include<iostream>
#include<cstdio>
using namespace std;
//#define Max 1000000000
int main()
{
    long n,m,i,j,lb,ub,mid,sub,maxc;

    while(cin >> n >> m)
    {
        long c[n];
        maxc=0;
        for(i=0; i<n; i++)
        {
            cin >> c[i];

            if(c[i]>maxc)
                maxc=c[i];
        }

        lb=maxc;
        ub=n*maxc;

        while(lb<ub)
        {
            mid = (lb+ub)/2;
            //printf("lb=%ld  ub=%ld  mid=%ld ",lb,ub,mid);
            j=0;

            for(i=0; i<m; i++)
            {
                //--j;
                sub=mid;
                while(sub>=c[j] && j<n)
                {
                    sub -= c[j];
                    j++;
                }
            }
            if(j<n) //not possible
            {
                lb=mid+1;
                //printf("not possible\n");
            }
            else// possible
            {
                ub=mid;
                //printf("possible\n");
            }
        }

        cout << lb << endl;
    }

    return 0;
}
