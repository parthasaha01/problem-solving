#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int id[MAXN];
vector<int>ans;
queue<int>qq;
queue<int>Q[MAXN];
int main()
{
    ios :: sync_with_stdio(false); cin.tie(0);

    int n,ks=0;
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1; i<=n; i++)
        {
            int k; cin>>k;
            for(int j=1; j<=k; j++)
            {
                int x; cin>>x;
                id[x] = i;
            }
        }

        string s;
        while(cin>>s)
        {
            if(s=="STOP")break;
            else if(s=="ENQUEUE")
            {
                int x; cin>>x;
                //cout << "x=" << x << " id=" << id[x];
                if(Q[id[x]].empty()){
                    qq.push(id[x]);
                    Q[id[x]].push(x);
                    //cout << " if" << endl;
                }
                else{
                    //cout << " else " << endl;
                    Q[id[x]].push(x);
                }
            }
            else
            {
                while(Q[qq.front()].empty()){
                    //cout << "while " << qq.front() << endl;
                    qq.pop();
                }


                //cout << "qq.front=" << qq.front() << " val=" << Q[qq.front()].front() << endl;
                ans.push_back(Q[qq.front()].front());
                Q[qq.front()].pop();
            }
        }

        cout << "Scenario #" << ++ks << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << endl;
        }
        cout << endl;

        ans.clear();
        while(!qq.empty()){
            while(!Q[qq.front()].empty()){
                Q[qq.front()].pop();
            }
            qq.pop();
        }
    }
    return 0;
}
