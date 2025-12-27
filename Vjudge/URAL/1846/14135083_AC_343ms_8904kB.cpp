#include<bits/stdc++.h>
using namespace std;
#define mx 100005
map<int,int>mp;
map<int,int>sp;
int a[mx],tree[4*mx];
struct dt{
    int t,v;
}qr[mx];
void update(int nd,int b,int e,int x,int t)
{
    if(b==e){
        if(t==1){
            //printf("nd=%d b=%d e=%d x=%d a[x]=%d sp[x]=%d t=%d\n",nd,b,e,x,a[x],sp[x],t);
            if(a[x]>0)tree[nd] = sp[x];
            else tree[nd] = 0;
            return;
        }
        else{
            if(a[x]>0)tree[nd] = sp[x];
            else tree[nd] = 0;
            return;
        }
    }

    int lf = 2*nd, rg = 2*nd+1, md = (b+e)/2;

    if(x<=md)update(lf,b,md,x,t);
    else update(rg,md+1,e,x,t);

    tree[nd] = __gcd(tree[lf],tree[rg]);
}
int main()
{
    //printf("%d\n",__gcd(0,5));
    int q; scanf("%d",&q);
    int k = 0;
    for(int i=1; i<=q; i++){
        getchar();
        char ch; int v;
        scanf("%c %d",&ch,&v);
        if(ch=='+'){
            if(mp.find(v)==mp.end()){
                mp[v] = ++k;
                sp[k] = v;
                //printf("k=%d sp[k]=%d\n",k,sp[k]);
            }
            qr[i].t = 1;
            qr[i].v = mp[v];

        }
        else{
            qr[i].t = 2;
            qr[i].v = mp[v];
        }
    }

    //printf("%d %d\n",sp[1],sp[2]);
    int n = k;

    for(int i=1; i<=q; i++)
    {
        int t = qr[i].t;
        int v = qr[i].v;

        //printf("%d %d\n",t,v);

        if(t==1){
            a[v]++;
            //printf("v=%d mp[v]=%d sp=%d\n",v,mv,sp[mp[v]]);
            update(1,1,n,v,1);
            printf("%d\n",max(1,tree[1]));
        }
        else{
            a[v]--;
            update(1,1,n,v,2);
            printf("%d\n",max(1,tree[1]));
        }
    }

    return 0;
}
