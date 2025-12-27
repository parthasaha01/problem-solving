//#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
vector<double>vl;
set<string>ss;
struct node{
    int cnt;
    node *next[300];
    node(){
        cnt = 0;
        for(int i=0; i<300; i++)next[i]=NULL;
    }
}*root;
void Insert(string s)
{
    node *cur = root;
    for(int i=0; i<s.size(); i++){
        int id;
        id = s[i];
        //if(s[i]==' ')id = 52;
        //else if(s[i]>='a' && s[i]<='z')id = s[i]-'a';
        //else if(s[i]>='A') id = s[i]-'A'+26;
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
        int id;
        id = s[i];
        //if(s[i]==' ')id = 52;
        //else if(s[i]>='a' && s[i]<='z')id = s[i]-'a';
        //else id = s[i]-'A'+26;

        cur = cur->next[id];
    }
    return cur->cnt;
}
void del(node *cur)
{
    for(int i=0; i<300; i++){
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    int tt;
    cin>>tt;
    getchar();
    getchar();

    for(int ks=1; ks<=tt; ks++)
    {
        string s;
        root = new node();
        int sz=0;

        while(getline(cin,s))
        {
            if(s.empty())break;

            Insert(s);
            ss.insert(s);
            sz++;
        }


        std::set<string>::iterator it1;
        for(it1=ss.begin(); it1!=ss.end() && sz; it1++)
        {
            int v = Search(*it1);
            double pr = ((double)v/(double)sz)*100.00;
            vl.push_back(pr);
        }

        int k=0;
        std::set<string>::iterator it2;
        for(it2=ss.begin(); it2!=ss.end(); it2++)
        {
            cout << *it2 << " ";
            printf("%.4lf\n",vl[k++]);
        }

        if(ks!=tt)printf("\n");

        del(root);
        vl.clear();
        ss.clear();
    }

    return 0;
}

