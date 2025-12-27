#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n,vs[30],mp[30],si[20][MAX];
struct dt{
    int id,sid,tp1,tp2;
}sa[20][MAX];

string s;
int lcp[MAX];
int t, cs = 1, m,k;
int globalstp;

// rnk[i] means value of ith suffix in the sorted suffix array
// A[i] means position of the ith suffix in the sorted suffix array
int A[MAX + 10], rnk[MAX + 10];
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
    memset(lcp, 0, sizeof(lcp));

    n = s.size();
    memset(vs,0,sizeof(vs));
    memset(mp,-1,sizeof(mp));
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
    for(k=1; (1<<k-1)<=n; k++)
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

        //print(k);

        sa[k][0].sid = 0;
        for(int i=1,j=0; i<n; i++)
        {
            if(sa[k][i].tp1>sa[k][i-1].tp1)sa[k][i].sid = ++j;
            else if (sa[k][i].tp2>sa[k][i-1].tp2)sa[k][i].sid = ++j;
            else sa[k][i].sid = j;
        }

        for(int i=0; i<n; i++) si[k][sa[k][i].id] = sa[k][i].sid;

        //print(k);
    }

    globalstp = k;
    for(int i=0; i<n; i++) A[i]=si[k-1][i];
    for(int i = 0; i < n; i++) rnk[A[i]] = i;

//    printf("k=%d\n",k);
//    for(int j=0; j<k; j++){
//        for(int i=0; i<n; i++)printf("%d ",si[j][i]);
//        printf("\n");
//    }
//    for(int i=0; i<n; i++)printf("%d ",sa[k-1][i].id);
//    printf("\n");
//    for(int i=0; i<n; i++)printf("%d ",A[i]);
//    printf("\n");
//    for(int i=0; i<n; i++)printf("%d ",rnk[i]);
//    printf("\n");

}
int LCP(int x, int y)
{
    n = s.size();
    int k, re = 0;
    if (x == y) return n - x;

    for (k = globalstp - 1; k >= 0 && x < n && y < n; k --){
        if (si[k][x] == si[k][y]){
            x += 1 << k, y += 1 << k, re += 1 << k;
        }
    }
    return re;
}

void getLCP()
{
    int n = s.size();
    for(int i = 1; i < n; i++){
        lcp[i] = LCP(rnk[i], rnk[i - 1]);
    }

}
int main()
{
    cin >> s >> k;

    buildSA();
    getLCP();

    int len = s.size();

    for(int i = 0; i < len; i++){

        int lenfromhere = len - rnk[i];

        int cmn = lcp[i];

//        cout << i << ' ' << rnk[i] << ' ' << cmn << ' ' << k << endl;

        for(int j = cmn + 1; j <= lenfromhere; j++){
            k--;
            for(int l = i + 1; l < len; l++){
                if(k == 0) break;
                if(lcp[l] >= j){
                    k--;
                }
                else break;
            }

            if(k == 0){
                for(int l = rnk[i], m = 0; m < j; l++, m++) printf("%c", s[l]);
                return 0;
            }

        }

    }

    printf("No such line.\n");

    return 0;
}
