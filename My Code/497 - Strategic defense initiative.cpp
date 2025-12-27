#include<bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll>st;
int k;
ll L[100005],a[100005],s[100005];
int binarySearch(int v)
{
    int lo=0;
    int hi=k;
    int ans;

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
    int tt; scanf("%d\n\n",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        k=1;
        string ss;
        while(getline(cin,ss))
        {
            if(ss.size()==0)break;

            ll x;
            stringstream convert(ss);
            convert>>x;
            a[k] = x;
            k++;
        }
        k--;

//        printf("k=%d\n",k);
//        for(int i=1; i<=k; i++){
//            printf("%lld ",a[i]);
//        }
//        printf("\n");

        s[0] = -10000000000000000;
        for(int i=1; i<=k; i++)s[i]=10000000000000000;

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
        printf("Max hits: %d\n",lis);

        while(!st.empty())
        {
            printf("%lld\n",st.top());
            st.pop();
        }
        if(ks<tt)printf("\n");
    }
    return 0;
}


