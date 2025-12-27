#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,win[100005],lose[100005];
struct node{
    int state,next[26];
    node(){
        state=0;
        memset(next,-1,sizeof(next));
    }
}tree[100005];
void Insert()
{
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        if(tree[cur].next[id]==-1){
            tree[cur].next[id] = ++cnt;
            tree[cnt] = node();
        }
        cur = tree[cur].next[id];
    }
}
void fun(int u)
{
    win[u]=0; lose[u]=0;
    int isleaf = 1;
    for(int i=0; i<26; i++){
        int v = tree[u].next[i];
        if(v!=-1){
            isleaf = 0;
            fun(v);
            win[u] |= !win[v];
            lose[u] |= !lose[v];
        }
    }
    if(isleaf==1)lose[u]=1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>s; Insert();
    }

    fun(0);

    if(win[0]==0) printf("Second\n");
    else if(win[0]==1&&lose[0]==1) printf("First\n");
    else{
        if(k&1) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}
/*
5 6
abas
dsfdf
abacaba
dartsidius
kolobok

4 2
aaaa
bbbb
ccccc
dumbavumba
*/
