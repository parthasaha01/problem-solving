#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int a[1002][1002];
int v[1002][1002];
int row[1002][4012];
int  col[1002][4012];
struct node
{
    int value;
    node *left,*right;
    node()
    {
        value=0;
        left=NULL;
        right=NULL;
    }
};

int quarryrow(int idd,int root,int st,int ed,int s,int e)
{
    //cout<<root<<"  --"<<st<<" "<<ed<<" "<<s<<" "<<e<<endl;
    if(st>e||ed<s)
    {
        //      cout<<"limit "<<endl;
        return -inf;
    }
    if(st>=s&&ed<=e)
    {
        //cout<<"find"<<endl;
        return row[idd][root];
    }
    int mid=(st+ed)/2;
    //cout<<"-- mid "<<mid<<endl;
    int x=-inf,y=-inf;
    //if(root->left!=NULL)
    x=quarryrow(idd,root*2,st,mid,s,e);
    // if(root->right!=NULL)
    y=quarryrow(idd,root*2+1,mid+1,ed,s,e);
    //cout<<"re "<<x<<" "<<y<<endl;
    return max(y,x);
}
int quarrycol(int idd,int root,int st,int ed,int s,int e)
{
    //cout<<root<<"  --"<<st<<" "<<ed<<" "<<s<<" "<<e<<endl;
    if(st>e||ed<s)
    {
        //      cout<<"limit "<<endl;
        return -inf;
    }
    if(st>=s&&ed<=e)
    {
        // cout<<"find"<<endl;
        return col[idd][root];
    }
    int mid=(st+ed)/2;
    //cout<<"-- mid "<<mid<<endl;
    int x=-inf,y=-inf;
    //if(root->left!=NULL)
    x=quarrycol(idd,root*2,st,mid,s,e);
    // if(root->right!=NULL)
    y=quarrycol(idd,root*2+1,mid+1,ed,s,e);
    //cout<<"re "<<x<<" "<<y<<endl;
    return max(y,x);
}

int inserttrow(int idd,int root ,int st,int ed,int p,int vv)
{
    // cout<<root<<" in -- "<<st<<" "<<ed<<" "<<p<<" "<<vv<<endl;
    //getchar();
    if(st==ed&&st==p)
    {
        //  cout<<"set"<<endl;
        return   row[idd][root]=vv;
    }
    int mid=(st+ed)/2,x, y;
    x=-inf;
    y=-inf;
    if(mid>=p)
    {
        x=max(x, inserttrow(idd,root*2,st,mid,p,vv));
        //root->left=new node();
    }
    else
    {
        y=max(y, inserttrow(idd,root*2+1,mid+1,ed,p,vv));
        // root->right=new node();
    }

    return row[idd][root]=max(row[idd][root*2],row[idd][root*2+1]);
    // int x=insertt()
}
int inserttcol(int idd,int root ,int st,int ed,int p,int vv)
{
    // cout<<root<<" in -- "<<st<<" "<<ed<<" "<<p<<" "<<vv<<endl;
    //getchar();
    if(st==ed&&st==p)
    {
        //  cout<<"set"<<endl;
        return   col[idd][root]=vv;
    }
    int mid=(st+ed)/2,x, y;
    x=-inf;
    y=-inf;
    if(mid>=p)
    {
        x=max(x, inserttcol(idd,root*2,st,mid,p,vv));
        //root->left=new node();
    }
    else
    {
        y=max(y, inserttcol(idd,root*2+1,mid+1,ed,p,vv));
        // root->right=new node();
    }

    return col[idd][root]=max(col[idd][root*2],col[idd][root*2+1]);
    // int x=insertt()
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int ks=1; ks<=t; ks++)
    {
        int r,c;
        scanf("%d%d",&r,&c);

        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                scanf("%d",&v[i][j]);

                inserttrow(i,1,1,c,j,v[i][j]);
                inserttcol(j,1,1,r,i,v[i][j]);
            }
        }

        int x=-inf,y=-inf,s;
        int ans=0;
        //memset(row,0,sizeof(row));
        //memset(col,0,sizeof(col));

        for(int i=r; i>0; i--)
        {
            for(int j=c; j>0; j--)
            {
                x=-inf,y=-inf;
                s=v[i][j];

                int mr,mc;
                mr=min(c,j+a[i][j]);
                if(j<mr)x=quarryrow(i,1,1,c,j+1,mr);

                mc=min(r,i+a[i][j]);
                if(i<mc) y=quarrycol(j,1,1,r,i+1,mc);

                x=max(x,y);
                if(x!=-inf) s+=x;
                if(i==1&&j==1) ans=s;

                inserttrow(i,1,1,c,j,s);
                inserttcol(j,1,1,r,i,s);
            }
        }

        printf("Case %d: %d\n",ks,ans);

//        for(int i=1;i<=r;i++) del(row[i]);
//        for(int i=1;i<=c;i++) del(col[i]);
    }
    return 0;
}

