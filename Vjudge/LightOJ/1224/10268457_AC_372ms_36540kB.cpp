#include<bits/stdc++.h>
using namespace std;
char s[55];
map<char,int>mp;
int maxx;
struct node{
    int cnt,lev;
    node *next[4];
    node(){
        cnt = 0; lev = 0;
        for(int i=0; i<4; i++)next[i]=NULL;
    }
}*root;
void Insert()
{
    node *cur = root;
    int sz = strlen(s);
    for(int i=0; i<sz; i++)
    {
        int id = mp[s[i]];
 
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
 
        cur = cur->next[id];
        cur->cnt++;
        cur->lev = i+1;
        int vv = (cur->cnt)*(cur->lev);
        maxx = max(maxx,vv);
    }
}
 
void del(node *cur)
{
    for(int i=0; i<4; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    mp['A']=0; mp['C']=1; mp['G']=2; mp['T']=3;
    int tt; scanf("%d",&tt);
 
    for(int ks=1; ks<=tt; ks++)
    {
        root = new node();
        int n; scanf("%d",&n);
        maxx=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",&s);
            Insert();
        }
        printf("Case %d: %d\n",ks,maxx);
        del(root);
    }
    return 0;
}