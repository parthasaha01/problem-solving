#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
int tree[mx*4],arr[mx];

void buildTree(int nd, int b, int e)
{
    if(b==e){
        tree[nd] = b;
        return;
    }
    int md = (b+e)/2;
    int lf = 2*nd;
    int rg = lf+1;
    buildTree(lf, b, md);
    buildTree(rg, md+1,e);

    if(arr[tree[lf]]>=arr[tree[rg]]){
        tree[nd] = tree[lf];
    }
    else{
        tree[nd] = tree[rg];
    }
}

int query(int nd,int b,int e,int x,int y)
{
    if(x>y)return 0;
    if(b>y || e<x)return 0;
    if(b>=x&&e<=y)return tree[nd];

    int lf = 2*nd; int rg = 2*nd+1; int md = (b+e)/2;

    int p1=query(lf,b,md,x,y);
    int p2=query(rg,md+1,e,x,y);

    if(arr[p1]>=arr[p2])return p1;
    else return p2;
}

void update(int nd,int b,int e,int idx)
{
    if(idx==b&&idx==e){
        tree[nd]=b;
        return;
    }
    int md=(b+e)/2;
    int lf = 2*nd;
    int rg = lf+1;
    if(idx<=md) update(lf, b, md,idx);
    else update(rg, md+1,e,idx);

    if(arr[tree[lf]]>=arr[tree[rg]]){
        tree[nd] = tree[lf];
    }
    else{
        tree[nd] = tree[rg];
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int tst=1; tst<=test; tst++)
    {
        int n; scanf("%d",&n);
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            q.push(u);
            q.push(v);
        }
        //tree[mx]=100000000;
        int l,f;
        scanf("%d%d",&l,&f);
        tree[0]=0;

        memset(arr,0,sizeof(arr));

        while(!q.empty())
        {
            int d = q.front();
            q.pop();
            int dfc = l-d;
            int f1 = q.front();
            q.pop();
            if(f1>100) f1=100;
            if(dfc>0) arr[dfc] = f1;
        }
//        for(int i=0; i<l; i++)
//            printf("%2d ",i);
//        cout<<endl;
//
//        for(int i=0; i<l; i++)
//            printf("%2d ",arr[i]);
//        printf("\n");

        buildTree(1,1,l);
//
//        for(int i=1; i<=l*3; i++)
//            cout<<tree[i]<<" ";
//        cout<<endl;
//cout<<arr[tree[20]]<< " "<<arr[tree[21]]<<endl;

        int total = f;
        //cout<<total<<endl;
        int cnt=0;
        int flag=0;
        while(total<l)
        {
            //cout<<l<<" "<<"1"<<" "<<total<<endl;
            int x = query(1,1,l,1,total);
            //cout<<x<<endl;
            //cout<<arr[x]<<endl;
            // getchar();

            if(arr[x]==0)
            {
                flag=1;
                break;
            }

//            if(x==n+1)
//            {
//                flag=1;
//                break;
//            }

            total+=arr[x];
            //cout<<arr[x]<<endl;
            //getchar();
            arr[x]=0;
            update(1,1,l,x);
            cnt++;
//            cout<<endl;
//            for(int i=1; i<=l*3; i++)
//                cout<<arr[tree[i]]<<" ";
//            cout<<endl;
        }
        if(flag==1)
            printf("-1\n");
        else
            printf("%d\n",cnt);
    }

    return 0;
}

/*
1
4
4 4
5 2
11 5
15 10
25 10


*/
