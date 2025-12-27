#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
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
    for(int i=0; i<s.size(); i++)
    {
        int id = s[i]-'a';
        if(tree[cur].next[id]==-1){
            tree[cur].next[id] = ++cnt;
            tree[cnt] = node();
        }
        cur = tree[cur].next[id];
    }
}
int fun1(int cur)
{
    int ret = 0;
    for(int i=0; i<26; i++){
        if(tree[cur].next[i]!=-1){
            ret |= fun1(tree[cur].next[i]);
        }
    }

    ret ^= 1;

    return ret;
}
int fun2(int cur)
{
    int ret = 0;
    int flag = 1;

    for(int i=0; i<26; i++){
        if(tree[cur].next[i]!=-1){
            flag = 0;
            ret |= fun2(tree[cur].next[i]);
        }
    }

    ret |= flag;
    ret ^= 1;

    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        Insert();
    }

    int win=!fun1(0);
    int lose=!fun2(0);

    if(win==0){
        printf("Second\n");
    }
    else if(win==1&&lose==1){
        printf("First\n");
    }
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
