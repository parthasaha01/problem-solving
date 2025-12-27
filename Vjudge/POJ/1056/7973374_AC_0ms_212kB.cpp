#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
string ss[20];
struct node{
    int cnt;
    bool endmark;
    node *next[2];
    node(){
        cnt = 0;
        endmark = false;
        for(int i=0; i<2; i++)next[i]=NULL;
    }
}*root;
void Insert(string s)
{
    node *cur = root;

    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
        cur->cnt++;
    }
}
bool Search(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i]-'0';
        cur = cur->next[id];
    }

    if(cur->cnt>1)return false;
    else return true;
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
    int k=0;
    int ks = 1;
    root = new node();
    while(cin>>ss[k])
    {
        if(ss[k]=="9")
        {
            for(int i=0; i<k; i++){
                Insert(ss[i]);
            }

            int flag = true;
            for(int i=0; i<k && flag; i++){
                flag = Search(ss[i]);
            }

            if(flag)printf("Set %d is immediately decodable\n",ks);
            else printf("Set %d is not immediately decodable\n",ks);


            del(root);
            root = new node();
            k = -1;
            ks++;
        }

        k++;
    }

    del(root);
    return 0;
}
