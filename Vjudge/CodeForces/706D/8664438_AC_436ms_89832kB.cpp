#include<bits/stdc++.h>
using namespace std;
int msz;
struct node{
    bool endmark;
    int cnt;
    int v;
    int ct;
    node *next[2];
    node(){
        endmark = false;
        cnt= 0;
        v=0;
        ct=0;
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
//    printf("n=%d sz=%d ",x,s.size());
//    cout << s << endl;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
        cur->ct++;
    }
    cur->endmark = true;
    cur->v = x;
    cur->cnt = cur->cnt + 1;
}
void Delete(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        cur = cur->next[id];
        cur->ct--;
    }
    cur->cnt = cur->cnt - 1;
    if(cur->cnt==0)cur->endmark = false;
}
int query(string s)
{
    node *cur = root;

    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        int nx = 1-id;
        if(cur->next[nx]==NULL || cur->next[nx]->ct==0)cur = cur->next[id];
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
