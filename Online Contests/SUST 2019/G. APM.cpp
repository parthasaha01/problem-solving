#include<bits/stdc++.h>
using namespace std;

map<string, int>mp;
map<int, string>mpr;
map<string, int>dmp;
map<string, int>severmp;
vector<string>dApnList;
vector<int> path[1001];

int visit [1003];

bool fun(int u){
   if(visit[u]){
       return true;
   }
   visit[u] = 1;
   int ans = true;

   string serverName = mpr[u];
   serverName =  serverName.substr(0, serverName.find(":"));

   if(dmp.find(serverName) != dmp.end()){
        ans = false;
   }
    dmp[serverName] = 1;
   for(int i=0;i<path[u].size() && ans;i++){
       int v = path[u][i];
       ans &= fun(v);
   }

   return ans;
}

int main(){

      int t;
      cin>>t;
      int cas = 0;
      int cnt = 0;
      int apnCnt = 0;
      while(t--){
            string apn;
            cin>>apn;

            int d;
            cin>> d;
            dmp.clear();
            dApnList.clear();
            int f = 1;
            string dapn;
            for(int i=0;i<d;i++){
                cin>>dapn;
                dApnList.push_back(dapn);
                if(mp.find(dapn)== mp.end()){
                    f = 0;
                }

            }
            printf("Request %d: ",++cas);

            if(f==0){
                printf("ERROR\n");
                continue;
            }

            memset(visit, 0 ,sizeof(visit));

            for(int i=0;i<d;i++){
               if(f){
                f&=fun(mp[dApnList[i]]);
               }
            }

           if(!f){
                printf("ERROR\n");
                continue;
           }
            printf("OK\n");

             mp[apn] = ++cnt;
             mpr[cnt] = apn;

             for(int i=0;i<d;i++){
               path[cnt].push_back(mp[dApnList[i]]);
            }

            map<string, int>::iterator it = mp.begin();

            while(it != mp.end()){
                cout<<it->first<<endl;
                it++;
            }
      }

      return 0;
}
