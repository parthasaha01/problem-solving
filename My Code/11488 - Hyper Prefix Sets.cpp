#include<bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    node *next[2];
    node(){
        cnt = 0;
        for(int i=0; i<2; i++)next[i]=NULL;
    }
}*root;
int Insert(char *s,int maxx)
{
    node *cur = root;
    int dp = 0;
    int sz = strlen(s);
    for(int i=0; i<sz; i++){
        int id;
        id = s[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
        cur->cnt++;
        dp++;
        maxx = max(maxx,(cur->cnt * dp));
    }
    return maxx;
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
    int tt; scanf("%d",&tt);
    while(tt--)
    {
        int n; scanf("%d",&n);
        char s[205];
        root = new node();
        int maxx = 0;
        for(int i=1; i<=n; i++){
            scanf("%s",s);
            maxx = max(maxx,Insert(s,maxx));
        }

        printf("%d\n",maxx);

        del(root);
    }

    return 0;
}
