#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define mp make_pair
#define pb push_back
const int BLOCK_SIZE = 320;
bool flag[mx],ans[mx];
int zero,neg,XOR;
int a[mx];
vector< pair<int,int> >factor[mx];
vector< pair<int, pair<int,int> > > qr[BLOCK_SIZE];
void sieve()
{
    for(int i=2; i<=100000; i++){
        if(!flag[i]){
            for(int j=i; j<=100000; j+=i){
                int k=0,v=j;
                while(v%i==0){
                    k++;
                    v/=i;
                }
                factor[j].pb(mp(i,k));
                flag[j]=true;
            }
        }
    }
}
void Add(int x)
{
    int v = a[x];

    if(v==0)zero++;
    else if(v<0)neg++;

    if(v<0)v*=(-1);
    if(v==0 ||v==1)return;

    for(int i=0; i<factor[v].size(); i++){
        int p = factor[v][i].first;
        int k = factor[v][i].second;
        if(k&1)XOR^=p;
    }
}
void Remove(int x)
{
    int v = a[x];

    if(v==0)zero--;
    else if(v<0)neg--;

    if(v<0)v*=(-1);
    if(v==0 ||v==1)return;

    for(int i=0; i<factor[v].size(); i++){
        int p = factor[v][i].first;
        int k = factor[v][i].second;
        if(k&1)XOR^=p;
    }
}
int main()
{
    sieve();

    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    int block = sqrt(n);

    for(int i=0; i<q; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        int block = x/BLOCK_SIZE;
        qr[block].pb(mp(y,mp(x,i)));
    }

    for(int i=0; i<BLOCK_SIZE; i++){
        sort(qr[i].begin(),qr[i].end());
    }

    zero=neg=XOR=0;
    int x=1,y=0;
    for(int k=0; k<BLOCK_SIZE; k++)
    {
        for(int i=0; i<qr[k].size(); i++)
        {
            int left = (qr[k][i].second).first;
            int right = qr[k][i].first;
            int idx = (qr[k][i].second).second;

            while(x<left) Remove(x++);
            while(x>left) Add(--x);
            while(y<right) Add(++y);
            while(y>right) Remove(y--);

            if(zero>0)ans[idx]=true;
            else if(neg&1)ans[idx]=false;
            else if(XOR==0)ans[idx]=true;
            else ans[idx]=false;
        }
    }

    for(int i=0; i<q; i++){
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
