#include<iostream>
#include<cstdio>
using namespace std;
int ara[100000];
int main()
{
    long N,S,i,j,cnt,Min,low,high,sum;

    while(cin >> N >> S)
    {
        for(i=0;i<N;i++)
        {
            scanf("%ld",&ara[i]);
        }
        sum=low=cnt=0;
        Min=100001;
        for(i=0;i<N && Min>1;i++)
        {
            sum += ara[i];
            cnt++;

            if(sum>=S)
            {
                sum-=ara[low];
                while(sum>=S)
                {
                    cnt--;
                    low++;
                    sum -= ara[low];
                }

                if(cnt<Min)
                {
                    Min=cnt;
                }

                low++;
                cnt--;

            }
        }

        if(Min>100000)
            cout << "0" << endl;
        else
            cout << Min << endl;
    }

    return 0;
}
