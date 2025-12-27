#include<bits/stdc++.h>
using namespace std;
vector<string>v[15];
string s[10005];
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            cin >> s[i];
            int d = s[i][0]-'0';
            v[d].push_back(s[i]);
        }

        for(int i=0; i<10; i++){
            sort(v[i].begin(),v[i].end());
        }

        bool flag=true;

        for(int i=0; i<10; i++)
        {
            int sz=v[i].size();

            for(int j=0; j<sz-1; j++)
            {
                string x=v[i][j];
                string y=v[i][j+1];

                bool same=true;
                for(int k=0; k<x.size(); k++)
                {
                    if(x[k]!=y[k]){
                        same=false;
                    }
                }

                if(same==true)
                {
                    flag=false;
                    goto label;
                }
            }
        }

        label:

        if(flag){
           printf("YES\n");
        }
        else{
            printf("NO\n");
        }

        for(int i=0; i<10; i++){
            v[i].clear();
        }
    }

    return 0;
}
