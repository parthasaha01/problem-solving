#include<bits/stdc++.h>
using namespace std;
#define mx 100005
char s[mx];
int n,step,vs[30],mp[30],si[20][mx],A[mx],rnk[mx],lcp[mx];
struct dt{
    int id,sid,tp1,tp2;
}sa[20][mx];
void print(int k)
{
    for(int i=0; i<n; i++)
    {
        printf("%2d (%d,%2d) %2d\n",sa[k][i].sid,sa[k][i].tp1,sa[k][i].tp2,sa[k][i].id);
    }
    printf("\n");
}
bool cmp(dt p,dt q)
{
    if(p.tp1==q.tp1){
        if(p.tp2==q.tp2)return p.id<q.id;
        return p.tp2<q.tp2;
    }
    return p.tp1<q.tp1;
}
void buildSA()
{
    memset(si, 0, sizeof(si));
    memset(rnk , 0 , sizeof(rnk));
    memset(A, 0, sizeof(A));
    memset(vs,0,sizeof(vs));
    memset(mp,-1,sizeof(mp));

    n = strlen(s);
    for(int i=0; i<n; i++) vs[s[i]-'a']=1;
    for(int i=0,j=0; i<26; i++) if(vs[i]!=0)mp[i]=j++;

    for(int i=0; i<n; i++)
    {
        sa[0][i].id = i;
        sa[0][i].sid = mp[s[i]-'a'];
        sa[0][i].tp1 = mp[s[i]-'a'];
        if(i+1<n)sa[0][i].tp2 = mp[s[i+1]-'a'];
        else sa[0][i].tp2 = -1;
    }

    sort(sa[0],sa[0]+n,cmp);

    for(int i=0; i<n; i++) si[0][sa[0][i].id] = sa[0][i].sid;

    int k,cnt;
    for(k=1,cnt=1; cnt<=n; cnt*=2, k++)
    {
        for(int i=0; i<n; i++)
        {
            sa[k][i].id = sa[k-1][i].id;
            sa[k][i].sid = sa[k-1][i].sid;
            sa[k][i].tp1 = sa[k-1][i].sid;
            if(sa[k][i].id+(1<<(k-1))<n)
                sa[k][i].tp2 = si[k-1][sa[k][i].id+(1<<(k-1))];
            else sa[k][i].tp2 = -1;
        }

        sort(sa[k],sa[k]+n,cmp);

        sa[k][0].sid = 0;
        for(int i=1,j=0; i<n; i++)
        {
            if(sa[k][i].tp1>sa[k][i-1].tp1)sa[k][i].sid = ++j;
            else if (sa[k][i].tp2>sa[k][i-1].tp2)sa[k][i].sid = ++j;
            else sa[k][i].sid = j;
        }

        for(int i=0; i<n; i++) si[k][sa[k][i].id] = sa[k][i].sid;
    }

    for(int i=0; i<n; i++) A[i]=si[k-1][i];
    for(int i = 0; i < n; i++) rnk[A[i]] = i;

    step = k;
//    printf("k=%d\n",k);
//    for(int j=0; j<k; j++){
//        for(int i=0; i<n; i++)printf("%d ",si[j][i]);
//        printf("\n");
//    }
//    printf("\n");
    for(int i=0; i<n; i++)printf("%d ",A[i]);
    printf("\n");
    for(int i=0; i<n; i++)printf("%d ",rnk[i]);
    printf("\n");
//    for(int i=0; i<n; i++)printf("%d ",sa[k-1][i].id);
//    printf("\n");
}
int getLCP(int x, int y)
{
    int ret = 0;
    for(int k=step-1; k>=0; k--)
    {
       // cout << si[i][x] << " " << si[i][y] << endl;
       // getchar();
        if(si[k][x]==si[k][y]){
            ret += (1<<k);
            x += (1<<k);
            y += (1<<k);
        }
    }
    return ret;
}
void buildLCP()
{
    memset(lcp,0,sizeof(lcp));
    for(int i=1; i<n; i++){
        lcp[i] = getLCP(rnk[i],rnk[i-1]);
    }

    for(int i=1; i<n; i++){
        printf("%d ",lcp[i]);
    }
    printf("\n");
}
int main()
{
    while(scanf("%s",s))
    {
        buildSA();
        buildLCP();
    }
    return 0;
}

