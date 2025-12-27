#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=2000000007;
int a[]={2,3,5,7};
vector<int>hum;
map<int,bool>mp;
void fun(ll v)
{
    if(v>inf || mp[v])return;
    hum.push_back(v);
    mp[v]=true;
    for(int i=0; i<4; i++){
        fun(v*a[i]);
    }
}
int main()
{
    hum.push_back(0);
    fun(1);
    sort(hum.begin(),hum.end());

    int n;
    while(scanf("%d",&n) && n)
    {
        string ch;
        if(n==1)ch="st";
        else if(n==2)ch="nd";
        else if(n==3)ch="rd";
        else if(n>=4&&n<=9)ch="th";
        else if(n%10==1 && (n/10)%10!=1)ch="st";
        else if(n%10==2 && (n/10)%10!=1)ch="nd";
        else if(n%10==3 && (n/10)%10!=1)ch="rd";
        else ch="th";

        cout<<"The "<<n<<ch<<" humble number is "<<hum[n]<<".\n";
    }
    return 0;
}
