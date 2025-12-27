#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int T,m,n,test,i,sum,num;

    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> m >> n;

        int power[10000];
        memset(power, 0, sizeof(power));

        sum=0;

        for(i=1; (m*i)<=n; i++)
        {
            num=m*i;
            power[num] = power[i]+1;
            sum+=power[num];
        }

        if(sum==0)
        {
            cout << "Case " << test << ":" << endl << "Impossible to divide" << endl;
        }
        else
        {
            cout << "Case " << test << ":" << endl << sum << endl;
        }
    }

    return 0;
}
