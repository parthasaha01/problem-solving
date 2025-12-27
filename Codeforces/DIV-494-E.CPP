#include<bits/stdc++.h>
using namespace std;
int deg[400005],lev[400005],flag[400005];
vector< pair<int,int> > v;
int possible(int n,int d,int k)
{
    int tot = 1;
    int sum = 1;
    for(int i=1; i<=d; i++)
    {
        sum*=k;
        tot+=sum;
        if(tot>=n)return 1;
    }
    return 0;
}
int main()
{
    int n,d,k;
    cin>>n>>d>>k;
    if(n<=d){
        cout << "NO" << endl;
        return 0;
    }

    if(d==1){
        if(n==2){
            cout << "YES" << endl;
            cout << 1 << " " << 2 << endl;

            return 0;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    if(k==1)
    {
        if(n==2 && d==1){
            cout << "YES" << endl;
            cout << 1 << " " << 2 << endl;

            return 0;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    else
    {
        if(d%2==0)
        {
//            if(!possible(n,d/2,k)){
//                cout << "NO" << endl;
//                return 0;
//            }

            int dd = d/2;
            int cur = 1;
            lev[1] = 0;
            for(int i=1; i<=dd; i++){
                deg[i]++;
                deg[cur+1]++;
                lev[cur+1] = lev[i]+1;
                v.push_back(make_pair(i,cur+1));
                cur++;
            }

//            for(int i=0; i<v.size(); i++){
//                cout << v[i].first << " " << v[i].second << endl;
//            }
//            cout << "haha-1" << endl;

            deg[1]++;
            deg[cur+1]++;
            lev[cur+1] = lev[1]+1;
            v.push_back(make_pair(1,cur+1));
            cur++;

//            for(int i=0; i<v.size(); i++){
//                cout << v[i].first << " " << v[i].second << endl;
//            }
//            cout << "haha-2" << endl;

            for(int i=cur; i<=d; i++){
                deg[i]++;
                deg[cur+1]++;
                lev[cur+1] = lev[i]+1;
                v.push_back(make_pair(i,cur+1));
                cur++;
            }

//            for(int i=0; i<v.size(); i++){
//                cout << v[i].first << " " << v[i].second << endl;
//            }
//            cout << "haha-3" << endl;

            for(int i=1; i<=n; i++)
            {
                if(i>cur)break;
                if(cur>=n)break;
                if(lev[i]==dd)continue;
                while(deg[i]<k)
                {
                    deg[i]++;
                    deg[cur+1]++;
                    lev[cur+1] = lev[i]+1;
                    v.push_back(make_pair(i,cur+1));
                    cur++;
                    if(cur>=n)break;
                }
            }

            if(cur<n){
                cout << "NO" << endl;
                return 0;
            }

            cout << "YES" << endl;
            for(int i=0; i<n-1; i++){
                cout << v[i].first << " " << v[i].second << endl;
            }

        }
        else
        {
            int dd = d/2;
            int cur = 1;
            lev[1] = 0;
            flag[1] = 0;
            for(int i=1; i<=dd+1; i++){
                deg[i]++;
                deg[cur+1]++;
                lev[cur+1] = lev[i]+1;
                flag[cur+1] = 1;
                v.push_back(make_pair(i,cur+1));
                cur++;
            }

            deg[1]++;
            deg[cur+1]++;
            lev[cur+1] = lev[1]+1;
            flag[cur+1] = 0;
            v.push_back(make_pair(1,cur+1));
            cur++;

//            for(int i=0; i<v.size(); i++){
//                cout << v[i].first << " " << v[i].second << endl;
//            }
//            cout << "haha" << endl;

            for(int i=cur; i<=d; i++){
                deg[i]++;
                deg[cur+1]++;
                lev[cur+1] = lev[i]+1;
                flag[cur+1] = flag[i];
                v.push_back(make_pair(i,cur+1));
                cur++;
            }

            for(int i=1; i<=n; i++)
            {
                if(i>cur)break;
                if(cur>=n)break;
                if(flag[i]==1 && lev[i]==dd+1)continue;
                if(flag[i]==0 && lev[i]==dd) continue;
                while(deg[i]<k)
                {
                    deg[i]++;
                    deg[cur+1]++;
                    lev[cur+1] = lev[i]+1;
                    flag[cur+1] = flag[i];
                    v.push_back(make_pair(i,cur+1));
                    cur++;
                    if(cur>=n)break;
                }
            }

            if(cur<n){
                cout << "NO" << endl;
                return 0;
            }

            cout << "YES" << endl;
            for(int i=0; i<n-1; i++){
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }

    return 0;
}
