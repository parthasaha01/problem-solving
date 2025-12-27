#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int FindPos(const vector<int>& primes, int valueWanted)
{
    int min(0), max(primes.size() - 1), mid;

    while (min < max)
    {
        mid = (min + max) / 2;

        if (primes[mid] > valueWanted)
            max = mid-1;    // max = mid, its also work
        else if (primes[mid] < valueWanted)
            min = mid + 1;
        else
            return mid;
    }

    return min;
}

int main()
{
    vector<bool> isPrime(32100, true);
    vector<int> primes;
    primes.push_back(2);

    long int i,j,doubleI;

    for (i=3; i<32100; i+=2)
    {
        if (isPrime[i])
        {
            primes.push_back(i);

            doubleI = i * 2;

            for (j=i*i; j<32100; j+=doubleI)
                isPrime[j] = false;

        }
    }

    int x,y,temp,diff1,diff2,diffn,m,n,Size;

    while (scanf("%d %d",&x,&y)==2)
    {
        if(x==0 && y==0)
            break;

        if(x>y)
        {
            temp=x;
            x=y;
            y=temp;
        }


        int min=FindPos(primes, x), max=FindPos(primes, y);

        if (primes[min] < x)
            ++min;

        if (primes[max] > y)
            --max;

        vector<int> diff;

        //printf("min=%d max=%d\n",min,max);

        for(i=min; i<=max-2;)
        {
            diff1=primes[i+1]-primes[i];
            diff2=primes[i+2]-primes[i+1];

            //printf("for %d %d diff1=%d %d diff2=%d\n",primes[i],primes[i+1],diff1,primes[i+2],diff2);

            if(diff1==diff2)
            {
                diff.push_back(primes[i]);
                diff.push_back(primes[i+1]);
                diff.push_back(primes[i+2]);

                diffn=diff1;

                //break;

                i+=2;

                while(i<=max-1)
                {
                    diff1=primes[i+1]-primes[i];

                    //printf("while %d %d diff1=%d %d diff2=%d\n",primes[i+m-2],primes[i+m-1],diff1,primes[i+m],diff2);

                    if(diff1!=diffn)
                    {
                        diff.push_back(0);
                        break;
                    }

                    diff.push_back(primes[i+1]);
                    i++;
                }

                if(i>=max)
                    diff.push_back(0);

            }
            else
            {
                i++;
            }
        }

        Size = diff.size();

        if(Size != 0)
        {
            i=0;

            if(primes[min]==diff[0])
            {
                diff1=primes[min]-primes[min-1];
                diff2=diff[1]-diff[0];

                if(diff1==diff2)
                {
                    i=0;
                    while(diff[i] != 0)
                    {
                        i++;
                    }
                    i++;
                }
            }

            if(primes[max] == diff[Size-2])
            {
                diff1=primes[max+1]-primes[max];
                diff2=diff[Size-2]-diff[Size-3];

                if(diff1==diff2)
                {
                    Size=Size-1;
                    while(diff[Size-1] != 0)
                    {
                        Size--;
                    }
                }
            }
            for(;i<Size;i++)
            {
                if(diff[i]==0)
                    printf("\n");
                else
                {
                    if(diff[i+1]==0)
                        printf("%d",diff[i]);
                    else
                        printf("%d ",diff[i]);

                }

            }


        }

    }

    return 0;
}

