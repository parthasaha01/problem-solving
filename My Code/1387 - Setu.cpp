#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        printf("Case %d:\n",kase);

        int n;
        scanf("%d",&n);
        double money=0;

        for(int i=0; i<n; i++)
        {
            string ss;
            cin >> ss;

            if(ss=="report"){
                if(money==(int)money)
                    printf("%.0lf\n",money);
                else
                    printf("%lf\n",money);
            }
            else{
                double amount;
                cin >> amount;
                money+=amount;
            }
        }
    }

    return 0;
}
