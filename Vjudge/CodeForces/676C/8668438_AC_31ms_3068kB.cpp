#include<bits/stdc++.h>
using namespace std;
int aa[100005],bb[100005],n,k;
string ss;
bool check(int x)
{
    for(int i=x; i<=n; i++){
        if(aa[i]-aa[i-x]<=k)return true;
        if(bb[i]-bb[i-x]<=k)return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&k);
    cin>>ss;

    for(int i=0; i<ss.size(); i++){
        if(ss[i]=='a'){
            aa[i+1]=aa[i]+1;
            bb[i+1]=bb[i];
        }
        else{
            aa[i+1]=aa[i];
            bb[i+1]=bb[i]+1;
        }
    }

    int lo=1;
    int hi=n;
    int ans=1;

    while(lo<=hi)
    {
        int md=(lo+hi)/2;
        if(check(md)){ ans=md; lo=md+1; }
        else hi=md-1;
    }

    printf("%d\n",ans);

    return 0;
}
