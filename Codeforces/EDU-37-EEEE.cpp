#include<bits/stdc++.h>
using namespace std;
vector<int>gr[200006];
int n,k;
int u,v;
vector<int>vl;
int tr[800003];
int ll,rr;
int update(int pos,int l,int r,int p)
{
    if(l==r)
    {
        tr[pos]=1;
        return 0;
    }
    if(l>r)
        return 0;
    int lf=pos*2;
    int rg=lf+1;
    int mid=(l+r)/2;
    if(p<=mid)
        update(lf,l,mid,p);
    else
        update(rg,mid+1,r,p);
    tr[pos]=tr[lf]+tr[rg];
}

int read(int pos,int l,int r)
{
//    cout<<pos<<" "<<l<<" "<<r<<endl;

    //getchar();
    if(l>r)
        return 0;
    if(ll<=l&&r<=rr)
        return tr[pos];
    if(l>rr||r<ll)
        return 0;
    int lf=pos*2;
    int rg=lf+1;
    int mid=(l+r)/2;
    int ret=0;

    ret+=read(lf,l,mid);
    ret+=read(rg,mid+1,r);
    return ret;
}


int left(int pos)
{
    int dif=pos;
    int pw=log2(dif+1);
    int ret=0;
    int cur=pos;

    while(pw>=0)
    {
        // pw=log2(dif);

        ll=cur-(1<<pw)+1;
        rr=cur;
        if(read(1,1,12)==(rr-ll+1))
        {
            ret+=(rr-ll+1);
            cur-=(1<<pw);
        }
        pw--;
    }
    return ret;
}

int right(int pos)
{
    int dif=n-pos+1;
    int pw=log2(dif+1);
    int ret=0;
    int cur=pos;

    while(pw>=0)
    {
        // pw=log2(dif);

        rr=cur+(1<<pw)-1;
        ll=cur;
        // cout<<rr<<" "<<ll<<endl;
        //cout<<read(1,1,12)<<endl;
        //getchar();
        if(read(1,1,12)==(rr-ll+1))
        {
            ret+=(rr-ll+1);
            cur+=(1<<pw);
        }
        pw--;
    }
    return ret;
}


int flag[200004];
int visit[200004];
int bin(int val)
{
    int l=0;
    int r=vl.size();
    r-=1;
    int pos=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(vl[mid]<=val)
        {
            pos=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return r;
}
int fun(int pos)
{
    if(visit[pos]) return 0;
    visit[pos]=1;
    update(1,1,n,pos);
    int cur=1;
    int ret=1;
    cur=cur+right(cur);

    for(int i=0; i<gr[pos].size(); i++)
    {
        int u=gr[pos][i];
        int x=left(u);
        if(x==0)
            x=1;
        u=u-x;
        ///  cout<<cur<<" left "<<u<<endl;
        // getchar();
        while(cur<=u)
        {
            ret+=fun(cur);
            cur++;
        }
        int y=right(gr[pos][i]);
        if(!y)
            y++;

        cur=gr[pos][i]+y;
    }

    int rgg=n-left(n);
    while(cur<=rgg)
    {
        ret+=fun(cur);
        cur++;
    }


    return ret;
}

vector<int>ans;
int ar[]= {0,1,1,0,1,1,0,1,1,1,1,0,0};
int main()
{
    n=12;
    //std::ios_base::sync_with_stdio(false);

    scanf("%d%d",&n,&k);
    for(int i=0; i<k; i++)
    {
        scanf("%d%d",&u,&v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        sort(gr[i].begin(),gr[i].end());
    }

    for(int i=1; i<=n; i++)
    {
        if(visit[i]==0)
        {
            ans.push_back(fun(i));
        }
    }

    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        if(i!=0) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
