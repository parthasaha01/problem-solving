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
    int flag = 0;
    int tot = 0;
    int win = 0;

    for(int i=0; i<26; i++)
    {
        if(tree[cur].next[i]!=-1){
            flag = 1;
           // string ss = s;
            //ss += i+'a';
            tot++;
            int f = fun1(tree[cur].next[i]);

            if(f==1)win++;
            if(cur==0)cout << win << " ";
            ret |= f;
        }
    }

    if(flag==0)ret = 0;

    if(cur==0){
        cout << "\nwin=" << win << " tot=" << tot << endl;
        if(tot==win)return 2;
        if(win==0)return 1;
        return 0;
    }

    ret ^= 1;

    //cout << s << " " << ret << endl;

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

    int win = fun1(0);
    cout << "win=" << win << endl;

    if(win==2)
    {
        if(k%2==1)printf("First\n");
        else printf("Second\n");

    }
    else if(win==1){
        printf("Second\n");
    }
    else{
        printf("First\n");
    }

    return 0;
}
/*
5 6
abas
dsfdfg
abacabab
dartsidius
kolobokl

4 2
aaaa
bbbb
ccccc
dumbavumba

*/
