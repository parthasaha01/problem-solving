#include<string>
#include<iostream>
using namespace std;
string ss[1005];
struct node{
    int cnt;
    bool endmark;
    node *next[26];
    node(){
        cnt = 0;
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
        cur->cnt++;
    }

    cur->endmark = true;
}
string Search(string s)
{
    node *cur = root;
    string tm;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'a';
        tm+=s[i];
        cur = cur->next[id];
        if(cur->cnt == 1)return tm;
    }
    return tm;
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
    int k=0;
    root = new node();

    while(cin>>ss[k])
    {
        Insert(ss[k]);
        k++;
    }

    for(int i=0; i<k; i++){
        cout << ss[i] << " " << Search(ss[i]) << endl;
    }

    del(root);

    return 0;
}
