#include<bits/stdc++.h>
using namespace std;
string ss[10005];
struct node{
    bool endmark;
    node *next[15];
    node(){
        endmark = false;
        for(int i=0; i<15; i++)next[i]=NULL;
    }
}*root;
bool Insert(string s)
{
    node *cur = root;
    bool flag = false;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        if(cur->next[id]==NULL){
            flag = true;
            cur->next[id] = new node();
        }
        cur = cur->next[id];
        if(cur->endmark==true)return false;
    }
    cur->endmark = true;
    return flag;
}
void del(node *cur)
{
    for(int i=0; i<15; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        root = new node();

        int n; scanf("%d",&n);

        for(int i=1; i<=n; i++){
            cin>>ss[i];
        }

        bool ans = true;
        for(int i=1; i<=n && ans; i++){
            ans = Insert(ss[i]);
        }

        if(ans)printf("Case %d: YES\n",ks);
        else printf("Case %d: NO\n",ks);

        del(root);
    }

    return 0;
}

