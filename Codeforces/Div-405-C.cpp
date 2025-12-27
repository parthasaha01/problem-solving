#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
vector<string>nam;
vector<string>ans;
string ss[55];
int main()
{

    for(char ch='A'; ch<='Z'; ch++)
    {
        string tm;
        tm += ch;
        nam.push_back(tm);
    }
    for(char ch='A'; ch<='Z'; ch++)
    {
        string tm;
        tm += ch;
        tm += 'a';
        nam.push_back(tm);
    }

    int n,k;
    cin >> n >> k;

    for(int i=1; i<=n-k+1; i++)cin>>ss[i];

    int cr=0;
    for(int i=0; i<k-1; i++){
        ans.push_back(nam[cr]);
        cr++;
    }


    for(int i=1; i<=n-k+1; i++)
    {
        if(ss[i]=="YES")
        {
            ans.push_back(nam[cr]);
            cr++;
        }
        else
        {
            int sz = ans.size();
            int p  = sz-k+1;
            ans.push_back(ans[p]);
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i==n-1)cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }

    return 0;
}

