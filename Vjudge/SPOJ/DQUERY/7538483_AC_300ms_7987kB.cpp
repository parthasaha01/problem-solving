#include<bits/stdc++.h>
using namespace std;
#define mxn 30009
#define mxq 200009

struct data{
    int st,ed,nmbr;

    bool operator < (const data& P) const{
        if(ed!=P.ed) return ed<P.ed;
        return st<P.st;
    }
}ques[mxq];;

int arr[mxn], tree[4*mxn], ans[mxq];
map<int, int>M;

void update(int node,int b,int e,int pos,int val)
{
    if(b>pos || e<pos) return;
    if(b==pos && e==pos){
        tree[node]=val; return;
    }

    int mid=(b+e)>>1, L=node<<1, R=L+1;

    update(L,b,mid,pos,val);
    update(R,mid+1,e,pos,val);

    tree[node]=tree[L]+tree[R];
}

int query(int node,int b,int e,int x,int y)
{
    if(b>y || e<x) return 0ll;
    if(b>=x && e<=y) return tree[node];

    int mid=(b+e)>>1, L=node<<1, R=L+1;

    int p1=query(L,b,mid,x,y);
    int p2=query(R,mid+1,e,x,y);
    return p1+p2;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        int q; scanf("%d",&q);

        for(int i=1;i<=q;i++)
        {
            int x,y; scanf("%d %d",&x,&y);
            ques[i].st=x; ques[i].ed=y;
            ques[i].nmbr=i;
        }

        sort(ques+1,ques+1+q);

        int k=1;
        for(int i=1; i<=q; i++)
        {
            while(k<=ques[i].ed)
            {
                if(M[arr[k]]==0)
                {
                    update(1,1,n,k,1);
                    M[arr[k]]=k;
                }
                else
                {
                    update(1,1,n,M[arr[k]],0);
                    update(1,1,n,k,1);
                    M[arr[k]]=k;
                }
                k++;
            }

            ans[ques[i].nmbr]=query(1,1,n,ques[i].st,ques[i].ed);
        }

        for(int i=1;i<=q;i++)
            printf("%d\n",ans[i]);

        M.clear();
    }
    return 0;
}
