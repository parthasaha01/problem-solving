#include<bits/stdc++.h>
using namespace std;
int a[5];
int calculate(int ans, int sign, int num)
{
    if(sign==1)
        return ans+num;
    if(sign==2)
        return ans-num;
    if(sign==3)
        return ans*num;
}
int main()
{
    int i,m,n,x,y,flag,ans;

    while(1)
    {
        for(i=0; i<5; i++)
            cin >> a[i];

        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0)
            break;

        sort(a,a+5);
        flag=0;

        for(m=1; m<=3; m++)
        {
            for(n=1; n<=3; n++)
            {
                for(x=1; x<=3; x++)
                {
                    for(y=1; y<=3; y++)
                    {
                        do
                        {
                            ans=a[0];
                            ans=calculate(ans,m,a[1]);
                            ans=calculate(ans,n,a[2]);
                            ans=calculate(ans,x,a[3]);
                            ans=calculate(ans,y,a[4]);

                            if(ans==23)
                            {
                                flag=1;
                                goto label;
                            }

                        }while(next_permutation(a,a+5));
                    }
                }
            }
        }

        label:
        if(flag)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}
