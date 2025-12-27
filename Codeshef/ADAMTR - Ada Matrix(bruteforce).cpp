#include<bits/stdc++.h>
using namespace std;
#define vvi vector< vector<int> >
map< vvi, int > mp;
vector< vvi > res;
int n;
void print(vvi a){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout<<a[i][j]<<" ";
            printf("%3d ",a[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
int bfs(vvi a){
    mp[a] = 1;
    queue<vvi>qq;
    qq.push(a);
    int cnt = 1;
    res.push_back(a);
    while(!qq.empty()){
        vvi u = qq.front();
        qq.pop();

        for(int i=0; i<n; i++){
            vvi v = u;
            for(int j=0; j<n; j++){
                swap(v[i][j], v[j][i]);
            }
            if(mp.find(v)==mp.end()){
                qq.push(v);
                mp[v] = 1;
                res.push_back(v);
                cnt++;
            }
        }
    }

    return cnt;
}
int main(){
    mp.clear();
    res.clear();
    vector< vector<int> >a;
    cin>>n;
    for(int i=0,x=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<n; j++){
            temp.push_back(++x);
        }
        a.push_back(temp);
    }

    //print();

    int cnt = bfs(a);
    cout<<cnt<<" "<<res.size()<<endl<<endl;
    for(int k=0; k<res.size(); k++){
        vvi b = res[k];
        print(b);
    }

    main();
    return 0;
}

