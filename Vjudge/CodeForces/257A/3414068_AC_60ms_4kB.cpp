#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,i,res,sum;

    while(cin >> n >> m >> k)
    {
        int a[n];
        for(i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        if(m<=k)
            res=0;
        else
        {
            sum=k-1;
            res=-1;
            for(i=n-1;i>=0;i--){
                sum+=a[i];
                if(sum>=m){
                    res=n-i;
                    break;
                }
                else
                    sum-=1;
            }
        }
        cout << res << endl;
    }

    return 0;
}
