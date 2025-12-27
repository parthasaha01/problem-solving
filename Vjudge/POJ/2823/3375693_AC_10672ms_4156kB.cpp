#include<iostream>
#include<cstdio>
using namespace std;
#define MX 1000000
long ara[MX];
long Max[MX];
long Min[MX];
int main()
{
    long n,k,i,cnt,j,index,low,high;

    while(cin >> n >> k)
    {
        for(i=0;i<n;i++)
            scanf("%ld",&ara[i]);

        low=0;
        high=0;
        Min[0]=0;
        //j=0;   //Min[low]=Min[high]=0

        for(i=1;i<k;i++)
        {
            if(ara[i]>ara[Min[high]])
            {
                Min[++high]=i;
            }
            else
            {

                while(high>=low)
                {
                    if(ara[i]>ara[Min[high]])
                    {
                        break;
                    }

                    --high;

                }
                if(high<low)
                {
                    Min[++high]=i;
                    low=high;
                }
                else
                {
                    Min[++high]=i;
                }

            }
        }
        cout << ara[Min[low]];
        for(i=k;i<n;i++)
        {
            if(ara[i]>ara[Min[high]])
            {
                Min[++high]=i;
            }
            else
            {

                while(high>=low)
                {
                    if(ara[i]>ara[Min[high]])
                    {
                        break;
                    }

                    --high;
                }
                if(high<low)
                {
                    Min[++high]=i;
                    low=high;
                }
                else
                {
                    Min[++high]=i;
                }
            }

            if(Min[low]<=i-k)
            {
                low++;
            }

            cout << " " << ara[Min[low]];
        }
        cout << endl;

        low=0;
        high=0;
        Max[0]=0;
        //j=0;   //Min[low]=Min[high]=0

        for(i=1;i<k;i++)
        {
            if(ara[i]<ara[Max[high]])
            {
                Max[++high]=i;
            }
            else
            {

                while(high>=low)
                {
                    if(ara[i]<ara[Max[high]])
                    {
                        break;
                    }

                    --high;

                }
                if(high<low)
                {
                    Max[++high]=i;
                    low=high;
                }
                else
                {
                    Max[++high]=i;
                }

            }
        }
        cout << ara[Max[low]];
        for(i=k;i<n;i++)
        {
            if(ara[i]<ara[Max[high]])
            {
                Max[++high]=i;
            }
            else
            {

                while(high>=low)
                {
                    if(ara[i]<ara[Max[high]])
                    {
                        break;
                    }

                    --high;
                }
                if(high<low)
                {
                    Max[++high]=i;
                    low=high;
                }
                else
                {
                    Max[++high]=i;
                }
            }

            if(Max[low]<=i-k)
            {
                low++;
            }

            cout << " " << ara[Max[low]];
        }
        cout << endl;
    }

    return 0;
}
