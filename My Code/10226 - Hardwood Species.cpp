#include<bits/stdc++.h>
using namespace std;
vector<double>vl;
set<string>ss;
struct node{
    int cnt;
    node *next[256];
    node(){
        cnt = 0;
        for(int i=0; i<256; i++)next[i]=NULL;
    }
}*root;
void Insert(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i];
        if(cur->next[id]==NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->cnt = cur->cnt + 1;
}
int Search(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id = s[i];
        cur = cur->next[id];
    }
    return cur->cnt;
}
void del(node *cur)
{
    for(int i=0; i<256; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    int tt;
    scanf("%d",&tt);
    getchar();
    getchar();

    for(int ks=1; ks<=tt; ks++)
    {
        char s[40];
        root = new node();
        int sz=0;
        while(gets(s) && strlen(s))
        {
            Insert(s);
            ss.insert(s);
            sz++;
        }
        set<string>::iterator it;
        for(it=ss.begin(); it!=ss.end() && sz; it++)
        {
            int v = Search(*it);
            double pr = ((double)v/(double)sz)*100.00;
            vl.push_back(pr);
        }

        int k=0;
        for(it=ss.begin(); it!=ss.end(); it++)
        {
            cout << *it << " ";
            printf("%.4lf\n",vl[k++]);
        }

        if(ks!=tt)printf("\n");

        del(root);
        vl.clear();
        ss.clear();
    }

    return 0;
}
