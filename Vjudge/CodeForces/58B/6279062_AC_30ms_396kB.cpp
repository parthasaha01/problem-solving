#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int n;
    int sq;

    while(cin >> n)
    {
        int sq=(int)sqrt((double)n);
        int k=0;
        if(n!=1)
            a[k++]=n;
        while(n!=1)
        {
            sq=(int)sqrt((double)n);
            int flag=1;
            for(int i=2; i<=sq; i++)
            {
                if(n%i==0)
                {
                    a[k++]=n/i;
                    flag=0;
                    n=n/i;
                    break;
                }
            }

            if(flag){
                break;
            }
        }

        a[k++]=1;

        sort(a,a+k,cmp);
        for(int i=0; i<k; i++)
        {
            if(i!=k-1)
                cout << a[i] << " ";
            else
                cout << a[i];
        }
        cout << endl;
    }

    return 0;
}
