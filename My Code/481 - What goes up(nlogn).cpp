#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 10000000000000000
stack<ll>st;
int k;
ll L[100005],a[100005],s[100005];
int binarySearch(int v)
{
    int lo=0; int hi=k; int ans;

    while(lo<=hi)
    {
        int md = (lo+hi)/2;

        if(s[md]<v){
            ans=md;
            lo=md+1;
        }
        else{
            hi = md-1;
        }
    }
    return ans+1;
}
void path(int lis)
{
    for(int i=k; i>=1 && lis>0; i--)
    {
        if(L[i]==lis){
            st.push(a[i]);
            lis--;
        }
    }
}
int main()
{
    while(scanf("%lld",&a[1])==1)
    {
        k=2;
        while(scanf("%lld",&a[k])==1){
            k++;
        }
        k--;

        s[0] = -inf;
        for(int i=1; i<=k; i++)s[i]=inf;

        int lis = 0;

        for(int i=1; i<=k; i++)
        {
            ll v = a[i];
            int p = binarySearch(v);
            s[p] = v;
            L[i] = p;
            lis = max(lis,p);
        }

//        for(int i=1; i<=k; i++)
//        {
//            printf("L[%d]=%d\n",i,L[i]);
//        }

        path(lis);
        printf("%d\n-\n",lis);

        while(!st.empty())
        {
            printf("%lld\n",st.top());
            st.pop();
        }
    }
    return 0;
}

