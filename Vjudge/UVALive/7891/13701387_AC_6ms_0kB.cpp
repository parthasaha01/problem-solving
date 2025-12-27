#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,s;
    int arr[10010];
    while(scanf("%d%d%d",&n,&c,&s)==3)
    {
        for(int i=0; i<c; i++)
        {
            scanf("%d",&arr[i]);
        }
        int res = 0;
        int val = 1;
        if(val==s)
            res++;
        for(int i=0; i<c; i++)
        {
            val+=arr[i];
            if(val==0)
                val = n;
            if(val==n+1)
                val = 1;
            if(val==s)
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
