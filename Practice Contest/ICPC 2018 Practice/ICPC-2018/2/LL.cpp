#include<bits/stdc++.h>
using namespace std;
vector<int>v[26];
void preprocess(char ch,int n,int mul,int add){
    for(int i=0; i<26; i++)v[i].clear();

    int id = ch-'a';
    v[id].push_back(0);
    //string s;
    //s += ch;
    for(int i=1; i<n; i++){
        int x = (id*mul)%26;
        int y = ((i%26)*(add%26))%26;
        id = (x+y)%26;
        v[id].push_back(i);
        //ch = id + 'a';
        //s += ch;
    }
    //cout << s << endl;
}
int Search(int id,int cur){
    int lo = 0, hi = (int)v[id].size()-1;
    int ans = -1;
    while(lo<=hi){
        int md = (lo+hi)/2;
        if(v[id][md]>cur){
            ans = v[id][md];
            hi = md-1;
        }
        else{
            lo = md+1;
        }
    }
    return ans;
}
int fun(char ch,int n,int mul,int add){
    int id = ch-'a';
    int cur = -1;
    cur = Search(id,cur);
    if(cur==-1)return 0;
    for(int i=1; i<n; i++){
        int x = (id*mul)%26;
        int y = ((i%26)*(add%26))%26;
        id = (x+y)%26;
        cur = Search(id,cur);
        if(cur==-1)return 0;
    }
    return 1;
}
int main(){
    freopen("mahdi.in","r",stdin);
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt;
    scanf("%d",&tt);

    //cin>>tt;
    for(int ks=1; ks<=tt; ks++){
        char ch; int n,mul,add;
        //cin>>ch>>n>>mul>>add;
        getchar();
        scanf("%c %d %d %d",&ch,&n,&mul,&add);

        preprocess(ch,n,mul,add);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",ks);
        //cin>>q;
        //cout<<"Case "<<ks<<":"<<endl;
        while(q--){
            //cin>>ch>>n>>mul>>add;
            getchar();
            scanf("%c %d %d %d",&ch,&n,&mul,&add);

            int ans = fun(ch,n,mul,add);
            if(ans)printf("BRAVO\n");
            else printf("REPEAT\n");
            //if(ans)cout<<"BRAVO"<<endl;
            //else cout<<"REPEAT"<<endl;
        }
    }
    return 0;
}
