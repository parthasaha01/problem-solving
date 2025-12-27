#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
int tree[mx*4],arr[mx];

void buildTree(int r, int b, int e)
{
    if(b==e)
    {
        tree[r] = arr[b];
        return;
    }
    int md = (b+e)/2;
    buildTree(r*2, b,md);
    buildTree(r*2 + 1, md+1,e);
    tree[r]=max(tree[r*2],tree[r*2+1]);
}

int query(int r, int b, int e, int l, int r1)
{
    if(b>r1||e<l)
        return 0;
    if(b>=l && e<=r1)
        return tree[r];
    int md=(b+3)/2;
    int x=  query(r*2,b,md,l,r1);
    int y= query(r*2+1,md+1,e,l,r1);
    return max(x,y);
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1; tst<=test; tst++)
    {
        int n;
        scanf("%d",&n);
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            q.push(u);
            q.push(v);
        }
        int l,f;
        scanf("%d%d",&l,&f);

        memset(arr,0,sizeof(arr));
        while(!q.empty())
        {
            int d = q.front();
            q.pop();
            int dfc = l -d;
            int f1 = q.front();
            q.pop();
            if(f1>100)
                f1=100;
            if(dfc>0)
                arr[dfc] = f1;
        }
        buildTree(1,1,l);

        for(int i=1;i<=l*3;i++)
            cout<<tree[i]<<" ";
        cout<<endl;

        int total = f;
        int cnt=0;
        while(total<l)
        {
            cout<<
            int x = query(1,1,l,1,total);
            total+=x;
            cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
