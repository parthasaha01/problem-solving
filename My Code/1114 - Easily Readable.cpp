#include<bits/stdc++.h>
using namespace std;
#define ll long long
char w[105],s[10005],ch;
int wz,sz;
struct node
{
    ll cnt;
    bool endmark;
    node *next[52];
    node()
    {
        cnt=0,endmark=false;
        for(int i=0; i<52; i++)next[i]=NULL;
    }
}*root;
void Insert()
{
    node *cur = root;
    for(int i=0; i<wz; i++)
    {
        int id;
        if(w[i]>='A'&&w[i]<='Z')id = w[i]-'A';
        else id = w[i]-'a'+26;
        if(cur->next[id]==NULL)
            cur->next[id] = new node();

        cur = cur->next[id];
    }

    cur->cnt++;
    cur->endmark=true;

}
ll Search()
{
    node *cur = root;
    for(int i=0; i<sz; i++)
    {
        int id;
        if(s[i]>='A'&&s[i]<='Z')id = s[i]-'A';
        else id = s[i]-'a'+26;
        if(cur->next[id]==NULL)return 0;
        cur = cur->next[id];
    }

    return cur->cnt;
}
void del(node *cur)
{
    for(int i=0; i<52; i++){
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
        int n; scanf("%d",&n);
        getchar();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",w);
            wz = strlen(w);
            getchar();
            if(wz>2)sort(w+1,w+wz-1);
            Insert();
            //printf("%s\n",w);
        }
        int q; scanf("%d",&q);
        getchar();
        while(q--)
        {
            ll ans = 1;

            while(scanf("%s%c",s,&ch))
            {

                sz = strlen(s);
                if(sz>2)sort(s+1,s+sz-1);
                //printf("%s ",s);
                ll cnt = Search();
                ans *= cnt;

                if(ch=='\n')break;
            }
           //printf("\n");
            //getchar();

            printf("%lld\n",ans);
        }

        del(root);
    }

    return 0;
}
