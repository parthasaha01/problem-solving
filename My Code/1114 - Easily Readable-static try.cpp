#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)
int indx;
struct node
{
    int cnt;
    int next[55];
    node(){
        cnt=0;
        for(int i=0; i<=52; i++)next[i]=-1;
    }
}tree[120005];

void Insert(string s)
{
    int cur=0;
    for(int i=0; i<s.size(); i++)
    {
        int id;
        if(s[i]>='A' && s[i]<='Z')id=s[i]-'A'+26;
        else id=s[i]-'a';

        if(tree[cur].next[id]==-1){
            tree[cur].next[id]=++indx;
            tree[indx]=node();
        }
        cur=tree[cur].next[id];
    }
    tree[cur].cnt++;
    return;
}

int query(string s)
{
    int cur=0;
    for(int i=0; i<s.size(); i++)
    {
        int id;
        if(s[i]>='A' && s[i]<='Z')id=s[i]-'A'+26;
        else id=s[i]-'a';

        cur=tree[cur].next[id];
        if(cur==-1)return 0;
    }
    return tree[cur].cnt;
}

int main()
{
    IO; // warning: we can not use both cin and scanf

    int t; cin>>t;
    for(int ks = 1; ks <= t; ks++)
    {
        indx=0;
        int n; cin>>n;

        for(int i=1; i<=n; i++)
        {
            string s; cin>>s;

            if(s.size()>2) sort(s.begin()+1, s.end()-1);
            Insert(s);
        }

        printf("Case %d:\n", ks);
        int m; cin>>m;
        cin.ignore(); //important, must use cin.ignore();

        for(int i=1; i<=m; i++)
        {
            int ans=1;
            string s,tm;
            getline(cin,s);
            stringstream ss(s);

            while(ss>>tm)
            {
                if(tm.size()>2) sort(tm.begin()+1, tm.end()-1);

                ans *= query(tm);
            }
            printf("%d\n", ans);
        }

        for(int i=0; i<=indx; i++)tree[i]=node();
    }
    return 0;
}
