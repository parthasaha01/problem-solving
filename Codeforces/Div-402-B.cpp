#include<bits/stdc++.h>
using namespace std;
#define ll long long
int fr[15];
int main()
{
    string ss;
    int k;

    while(cin>>ss>>k)
    {
        if(ss=="0"){
            printf("0\n");
            continue;
        }
        int sz = ss.size();
        int ps=1000000;
        int cnt=0;
        bool flag = false;
        for(int i=sz-1; i>=0; i--)
        {
            if(ss[i]=='0')cnt++;

            if(cnt==k){
                flag = true;
                //cout << sz << " " << i << " " << k << endl;
                ps = (sz-i)-k;
                break;
            }
        }

        memset(fr,0,sizeof(fr));

        for(int i=0; i<ss.size(); i++){
            fr[ss[i]-'0']++;
        }

        int tm = sz-1;

        int ans = min(ps,tm);

        //if(sz==fr[0])ans=sz;

        printf("%d\n",ans);
    }

    return 0;
}
