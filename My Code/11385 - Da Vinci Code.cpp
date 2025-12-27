#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>v;
ll fb[10005];
bool vis[205];
int main()
{
    map<ll, int>mp;
    ll a=0;ll b=1;
    for(int i=0; i<=50; i++)
    {
        ll c=a+b;
        mp[c]=i;
        a=b;b=c;
    }

    int t;
    scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        v.clear();

        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%lld",&fb[i]);
            v.push_back(mp[fb[i]]);
        }
        getchar();
        string s;
        getline(cin,s);
        //cout << s << endl;

        string ss;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='A'&&s[i]<='Z'){
                ss+=s[i];
            }
        }

        //cout << ss << endl;

        int len=ss.size();
        int sz=min(len,n);

        char ans[200];
        memset(vis,false,sizeof(vis));
        int maxx=0;

        for(int i=0; i<sz; i++)
        {
            char ch=ss[i];
            int dx=v[i];
            ans[dx]=ch;
            vis[dx]=true;
            maxx=max(maxx,dx);
        }

        for(int i=0; i<=maxx; i++){
            if(!vis[i]){
                ans[i]=' ';
            }
        }
        ans[maxx+1]='\0';

        printf("%s\n",ans);
    }

    return 0;
}
