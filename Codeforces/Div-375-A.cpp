#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,x3;
    while(cin>>x1>>x2>>x3)
    {
        int ans=999999999;

        for(int i=1; i<=100; i++)
        {
            int dis=0;
            dis+=abs(i-x1);
            dis+=abs(i-x2);
            dis+=abs(i-x3);

            if(dis<ans){
                ans=dis;
            }

        }
        cout << ans << endl;
    }

    return 0;
}
