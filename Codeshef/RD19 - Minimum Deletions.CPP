#include<bits/stdc++.h>
using namespace std;
unordered_set< int >ss[50005];
unordered_set<int>s;
int a[1005];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        s.clear();
        //for(int i=0; i<=50000; i++)ss[i].clear();

        int n; scanf("%d",&n);

        int gcd  = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]);
            gcd = __gcd(gcd,a[i]);
            s.insert(a[i]);
        }

        if(gcd==1){
            printf("0\n");
            continue;
        }

        //printf("partha\n");

        int ans = n-(int)s.size();
        int k = s.size();
        unordered_set<int>:: iterator it,jt;

        for(it=s.begin(); it!=s.end(); it++)
        {
            //int cnt =0;
            for(jt=s.begin(); jt!=s.end(); jt++)
            {
                if(*it==*jt)continue;
                if(__gcd(*it,*jt)!=1){
                    ss[*it].insert(*jt);
                }
            }

        }

        while(!s.empty())
        {
            int maxx = 0;
            int v=0;
            for(it=s.begin(); it!=s.end(); it++)
            {
                int sz = ss[*it].size();
                if(sz>maxx){
                    maxx = sz;
                    v = *it;
                }
            }

            //printf("partha\n");
            if(maxx==0){
                //printf("partha1\n");
                break;
            }

            for(it=ss[v].begin(); it!=ss[v].end(); it++)
            {
                int x = *it;
                ss[x].erase(v);
            }
            ans++;
            s.erase(v);

        }

        int g = 0;
        for(it=s.begin(); it!=s.end(); it++)
        {
            //cout << (*it) << endl;
            g = __gcd(g,*it);
            //ss[*it].clear();
        }

       // cout << g << endl;

        if(g!=1)ans=-1;

        printf("%d\n",ans);


        for(int i=1; i<=n; i++){
            ss[a[i]].clear();
        }

    }

    return 0;
}
