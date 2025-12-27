#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long minimum,sum,time;
    int n,m,d,r,i,j;
    while(cin >> n >> d >> r)
    {
        if(!n && !d && !r)
            break;

        int morning[n],evening[n];
        for(i=0;i<n;i++)
            cin >> morning[i];
        for(i=0;i<n;i++)
            cin >> evening[i];

        sort(morning,morning+n);
        sort(evening,evening+n);

        time=0;
        j=n-1;
        for(i=0,j=n-1; i<n; i++,j--)
        {
            sum = morning[i]+evening[j];

            if(sum>d)
                time += (sum-d);

        }

        minimum=time*r;

        cout << minimum << endl;
    }

    return 0;
}
