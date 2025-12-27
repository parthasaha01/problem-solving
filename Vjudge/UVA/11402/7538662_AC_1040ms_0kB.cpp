#include<bits/stdc++.h>
using namespace std;

#define L n*2
#define R n*2+1
#define M (int)((b+e)/2)
#define Node tree[n]
#define Right tree[R]
#define Left tree[L]

struct info{
    int s,p;
} tree[4*1024006];
string s;

void Build(int n, int b, int e)
{
    if(b==e){
        Node.s = s[b]-'0';
        Node.p = -1; return;
    }

    Build(L,b,M);
    Build(R,M+1,e);
    Node.s = Left.s + Right.s;
}

void Update(int n, int b, int e, int x, int y, int v)
{
    if(Node.p!=-1)
    {
        if(Node.p==2) Node.s = (e-b+1) - Node.s;
        else Node.s = (e-b+1) * Node.p;
        if(b!=e)
        {
            if(Node.p==2)
            {
                if(Left.p==0) Left.p=1;
                else if(Left.p==1) Left.p=0;
                else if(Left.p==2) Left.p=-1;
                else if(Left.p==-1) Left.p=2;

                if(Right.p==0) Right.p=1;
                else if(Right.p==1) Right.p=0;
                else if(Right.p==2) Right.p=-1;
                else if(Right.p==-1) Right.p=2;
            }
            else Left.p = Right.p = Node.p;
        }
        Node.p = -1;
    }
    if(b>y || e<x) return;
    if(b>=x && e<=y)
    {
        if(v==2) Node.s = (e-b+1) - Node.s;
        else Node.s = (e-b+1)*v;
        if(v==2)
        {
            if(Left.p==0) Left.p=1;
            else if(Left.p==1) Left.p=0;
            else if(Left.p==2) Left.p=-1;
            else if(Left.p==-1) Left.p=2;

            if(Right.p==0) Right.p=1;
            else if(Right.p==1) Right.p=0;
            else if(Right.p==2) Right.p=-1;
            else if(Right.p==-1) Right.p=2;
            return;
        }
        Left.p = Right.p = v;
        return;
    }
    Update(L,b,M,x,y,v);
    Update(R,M+1,e,x,y,v);
    Node.s = Left.s + Right.s;
}

int Find(int n, int b, int e, int x, int y)
{
    if(Node.p!=-1)
    {
        if(Node.p==2) Node.s = (e-b+1) - Node.s;
        else Node.s = (e-b+1) * Node.p;
        if(b!=e)
        {
            if(Node.p==2)
            {
                if(Left.p==0) Left.p=1;
                else if(Left.p==1) Left.p=0;
                else if(Left.p==2) Left.p=-1;
                else if(Left.p==-1) Left.p=2;

                if(Right.p==0) Right.p=1;
                else if(Right.p==1) Right.p=0;
                else if(Right.p==2) Right.p=-1;
                else if(Right.p==-1) Right.p=2;
            }
            else Left.p = Right.p = Node.p;
        }
        Node.p = -1;
    }

    if(b>y || e<x) return 0;
    if(b>=x && e<=y) return Node.s;
    int f1 = Find(L,b,M,x,y);
    int f2 = Find(R,M+1,e,x,y);
    return f1+f2;
}

int main()
{
    int t; scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        printf("Case %d:\n",ks);
        int m; scanf("%d",&m);

        s="0";
        while(m--)
        {
            int sz; scanf("%d",&sz);
            string str; cin>>str;
            while(sz--) s+=str;
        }

        int n = s.size()-1;
        for(int i=0; i<=4*n; i++){
            tree[i].s=0, tree[i].p=-1;
        }

        Build(1,1,n);

        int q; scanf("%d",&q);
        int qs=1;
        while(q--)
        {
            int x,y;
            char ch;
            getchar();
            scanf("%c%d%d",&ch,&x,&y);
            x++; y++;

            if(ch=='F') Update(1,1,n,x,y,1);
            if(ch=='E') Update(1,1,n,x,y,0);
            if(ch=='I') Update(1,1,n,x,y,2);
            if(ch=='S'){
                int ans = Find(1,1,n,x,y);
                printf("Q%d: %d\n",qs++,ans);
            }
        }
    }
    return 0;
}

/*
2

2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10

3
3
1
4
0
2
0
2
I 0 2
S 0 8
*/
