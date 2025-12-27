#include<bits/stdc++.h>
using namespace std;
int msz;
struct node{
    int cnt;
    int v;
    node *next[2];
    node(){
        cnt = v = 0;
        next[0] = next[1] = NULL;
    }
}*root;
string DecToBin(int x)
{
    string tm;
    while(x!=0){
        tm += (x&1)+'0';
        x = x>>1;
    }
    while(tm.size()<msz) tm+='0';

    reverse(tm.begin(),tm.end());
    return tm;
}
void Insert(string s,int x)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
        cur->cnt++;
    }
    cur->v = x;
}
void Delete(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        cur = cur->next[id];
        cur->cnt--;
    }
}
int query(string s)
{
    node *cur = root;

    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        int nx = 1-id;
        if(cur->next[nx]==NULL || cur->next[nx]->cnt==0)cur = cur->next[id];
        else cur = cur->next[nx];
    }
    return cur->v;
}
void del(node *cur)
{
    for(int i=0; i<2; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    root = new node();
    msz  = floor(log2(1000000000))+1;
    string zero = DecToBin(0);
    Insert(zero,0);

    int q; scanf("%d",&q);
    getchar();

    for(int i=1; i<=q; i++)
    {
        char ch; int x;
        scanf("%c %d",&ch,&x);
        getchar();

        if(ch=='+'){
            string s = DecToBin(x);
            Insert(s,x);
        }
        else if(ch=='-'){
            string s = DecToBin(x);
            Delete(s);
        }
        else{
            string s = DecToBin(x);
            int v = query(s);
            int ans = x^v;
            printf("%d\n",ans);
        }
    }

    del(root);

    return 0;
}
