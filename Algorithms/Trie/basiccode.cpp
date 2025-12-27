#include<bits/stdc++.h>
using namespace std;
struct node{
    bool endmark;
    node *next[26];
    node(){
        endmark = false;
        for(int i=0; i<26; i++)next[i]=NULL;
    }
}*root;
void Insert(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = true;
}
bool Search(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        if(cur->next[id]==NULL) return false;
        cur = cur->next[id];
    }
    return cur->endmark;
}
void del(node *cur)
{
    for(int i=0; i<26; i++){
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

        printf("Case %d:\n",ks);
        printf("Enter Number of Words: ");
        int n; scanf("%d",&n);
        printf("Enter all %d Words:\n",n);
        for(int i=1; i<=n; i++){
            string s; cin>>s;
            Insert(s);
        }
        printf("Enter Number of Query: ");
        int q; scanf("%d",&q);

        for(int i=1; i<=q; i++){
            string s; cin>>s;
            bool ans = Search(s);
            if(ans)printf("YES\n");
            else printf("NO\n");
        }
        del(root);
    }
    return 0;
}
