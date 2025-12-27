#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
#define ll long long int
int a[101];
ll pos[101];

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    memset(pos,-1,sizeof(pos));
    int cnt=0;

    for(int i=0; i<n; i++)
    {
        if('a'<=s[i]&&s[i]<='z')
        {
            if(a[s[i]-'a']==0)
                cnt++;

            a[s[i]-'a']=1;
        }

        if('A'<=s[i]&&s[i]<='Z')
        {
            if(a[s[i]-'A'+26]==0)
                cnt++;

            a[s[i]-'A'+26]=1;
        }

    }

    ll dif=100000000;

    for(int i=0; i<n; i++)
    {
        if('a'<=s[i]&&s[i]<='z')
        {

            if(pos[s[i]-'a']==-1)
                cnt--;
            pos[s[i]-'a']=i;

        }

        if('A'<=s[i]&&s[i]<='Z')
        {
            if(pos[s[i]-'A'+26]==-1)
                cnt--;
            pos[s[i]-'A'+26]=i;

        }

        if(cnt==0)
        {
            ll mx=0,mn=1000000000;

            for(int j=0; j<55; j++)
            {
                if(pos[j]!=-1)
                {
                    mx=max(pos[j],mx);
                    mn=min(pos[j],mn);

                }
            }

            dif=min(dif,mx-mn+1);
        }
    }
    cout<<dif<<endl;
}
