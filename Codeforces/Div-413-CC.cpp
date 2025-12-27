#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int b[mx],p[mx],t[mx],maxp[mx],maxq[mx],mxpd[mx],mxqd[mx],secp[mx],secq[mx];
struct dt
{
    int b,p,t,id;
}st[mx],pp[mx],qq[mx];
bool cmp1(dt aa, dt bb)
{
    if(aa.p==bb.p){
        return aa.b<bb.b;
    }
    else{
        return aa.p<bb.p;
    }
}
int main()
{
    int n,c,d,cc,dd;
    scanf("%d%d%d",&n,&c,&d);

    cc=c;
    dd=d;
    int x=0;
    int y=0;

    for(int i=1; i<=n; i++)
    {
        int u,v; char ch;
        scanf("%d %d %c",&u,&v,&ch);
        st[i].b = u;
        st[i].p = v;
        st[i].id = i;
        if(ch=='C'){
            x++;
            pp[x].b  = u;
            pp[x].p  = v;
            pp[x].id = i;
            st[i].t  = 1;
        }
        else
        {
            y++;
            qq[y].b  = u;
            qq[y].p  = v;
            qq[y].id = i;
            st[i].t  = 2;
        }
    }

    sort(pp+1,pp+x+1,cmp1);
    sort(qq+1,qq+y+1,cmp1);

    for(int i=1; i<=x; i++)
    {
        if(pp[i].b>=maxp[i-1]){
            secp[i]=maxp[i-1];
            maxp[i]=pp[i].b;
            mxpd[i]=pp[i].id;
        }
        else{
            if(pp[i].b>secp[i-1]){
                secp[i]=pp[i].b;
                maxp[i]=maxp[i-1];
                mxpd[i]=mxpd[i-1];
            }
            else
            {
                maxp[i]=maxp[i-1];
                mxpd[i]=mxpd[i-1];
                secp[i]=secp[i-1];
            }
        }
    }

    for(int i=1; i<=y; i++)
    {
        if(qq[i].b>=maxq[i-1]){
            secq[i]=maxq[i-1];
            maxq[i]=qq[i].b;
            mxqd[i]=qq[i].id;
        }
        else{
            if(qq[i].b>secq[i-1]){
                secq[i]=qq[i].b;
                maxq[i]=maxq[i-1];
                mxqd[i]=mxqd[i-1];
            }
            else
            {
                maxq[i]=maxq[i-1];
                mxqd[i]=mxqd[i-1];
                secq[i]=secq[i-1];
            }
        }
    }

//    for(int i=1; i<=x; i++){
//        printf("b=%d p=%d id=%d\n",pp[i].b,pp[i].p,pp[i].id);
//    }
//    printf("\n");
//    for(int i=1; i<=y; i++){
//        printf("b=%d p=%d id=%d\n",qq[i].b,qq[i].p,qq[i].id);
//    }

    int maxx = 0;

    for(int i=1; i<=n; i++)
    {
        int u,v,ch,id;
        u = st[i].b;
        v = st[i].p;
        ch = st[i].t;
        id = st[i].id;
        c=cc;
        d=dd;

        int sum=0;

        if(ch==1)
        {
            if(v<=c){
                sum+=u;
                c -= v;
            }
            else{
                continue;
            }
        }
        else
        {
            if(v<=d){
                sum+=u;
                d -= v;
            }
            else{
                continue;
            }
        }

        //printf("i=%d id=%d ch=%d\n",i,id,ch);

        int lo = 1;
        int hi = x;
        int res1=0;
        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            int p = pp[md].p;

            if(p<=c){
                lo = md+1;
                if(pp[md].id==i){
                    if(md>1){
                        res1=max(res1,maxp[md-1]);
                    }
                    continue;
                }
                else{
                    if(maxp[md]>res1)
                    {
                        if(mxpd[md]!=i){
                            res1=maxp[md];
                        }
                        else{
                            res1=secp[md];
                        }
                    }
                }
            }
            else{
                hi = md-1;
            }
        }

        lo = 1;
        hi = y;
        int res2=0;
        while(lo<=hi)
        {
            int md = (lo+hi)/2;
            int p = qq[md].p;

            if(p<=d){
                lo = md+1;
                //printf("i=%d id=%d\n",i,qq[md].id);
                if(qq[md].id==i){
                    if(md>1){
                        res2=max(res2,maxq[md-1]);
                    }
                    continue;
                }
                else{
                    if(maxq[md]>res2)
                    {
                        if(mxqd[md]!=i){
                            res2=maxq[md];
                        }
                        else{
                            res2=secq[md];
                        }
                    }
                }
            }
            else{
                hi = md-1;
            }

        }

        //printf("i=%d res1=%d res2=%d\n",i,res1,res2);

        if(res1==0 && res2==0){
            continue;
        }

        if(res1>=res2){
            sum += res1;
        }
        else{
            sum += res2;
        }

        if(sum>maxx){
            maxx=sum;
        }

        //printf("maxx=%d\n",maxx);
    }

    printf("%d\n",maxx);

    return 0;
}
/*
6 68 40
1 18 D
6 16 D
11 16 D
7 23 D
16 30 D
2 20 D
*/
