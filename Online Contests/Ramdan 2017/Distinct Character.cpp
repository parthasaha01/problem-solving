#include<bits/stdc++.h>
using namespace std;
//int cnt[30][500010];
int ans[500010];
map<int,int>mp;
string s;
int main()
{
    while(cin>>s)
    {
        s="0"+s;
        //cout << s << endl;
        //memset(cnt,0,sizeof(cnt));
        mp.clear();
        int p=0;
        for(int i=1; i<s.size(); i++)
        {
            int v = s[i]-'a'+1;
            if(mp[v]==0)
            {
                p++;
                ans[i]=p;
                mp[v]=1;
            }
            else
            {
                ans[i]=p;
            }
//            for(int j=1; j<=26; j++)
//            {
//                cnt[j][i]=cnt[j][i-1];
//            }
//            cnt[v][i]++;
        }

        int q; scanf("%d",&q);

        for(int k=1; k<=q; k++)
        {
            int v; scanf("%d",&v);
            printf("%d\n",ans[v]);

        }
    }
    return 0;
}
