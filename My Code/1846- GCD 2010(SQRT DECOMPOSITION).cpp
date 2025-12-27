#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define mx 100005
int BLOCK_SIZE;
map<int,int>mp;
map<int,int>sp;
int a[mx],block[325];
int GCD(int x,int y){
    if(x==0)return y;
    if(y==0)return x;
    return GCD(y,x%y);
}
struct dt{
    int t,v;
}qr[mx];
void update(int v)
{
    int b = v/BLOCK_SIZE;
    int l = b*BLOCK_SIZE;
    int r = ((b+1)*BLOCK_SIZE)-1;

    block[b] = 0;
    for(int i=l; i<=r; i++){
        if(a[i]>0)block[b] = GCD(block[b],sp[i]);
    }

}
int query()
{
    int gcd = 0;
    for(int i=0; i<=BLOCK_SIZE; i++){
        gcd = GCD(gcd,block[i]);
    }

    return gcd;
}
int main()
{
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
            }
            qr[i].t = 1;
            qr[i].v = mp[v];

        }
        else{
            qr[i].t = 2;
            qr[i].v = mp[v];
        }
    }

    int n = k;
    BLOCK_SIZE = sqrt(n)+1;
    int gcd = 0;
    for(int i=1; i<=q; i++)
    {
        int t = qr[i].t;
        int v = qr[i].v;

        if(t==1){
            a[v]++;
            if(a[v]==1){
                update(v);
                gcd = GCD(gcd,sp[v]);
            }
            printf("%d\n",max(1,gcd));
        }
        else{
            a[v]--;
            if(a[v]==0){
                update(v);
                gcd = query();
            }
            printf("%d\n",max(1,gcd));
        }
    }

    return 0;
}
