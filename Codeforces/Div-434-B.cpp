#include<bits/stdc++.h>
using namespace std;
int n,m;
int last[105];
set<int>ss;
struct data
{
    int k,f,d;
}st[105];
bool cmp(data a,data b)
{
    return a.k<b.k;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        int k,f,d;
        scanf("%d%d",&k,&f);

//        last[f]=max(last[f],k);
//
//        if(k==n)
//        {
//            ans = f;
//        }

        st[i].k=k;
        st[i].f=f;
        st[i].d=d;
    }

//    if(ans!=-1){
//        printf("%d\n",ans);
//        return 0;
//    }

//    if(n==1)
//    {
//        printf("1\n");
//        return 0;
//    }

//    if(m==0)
//    {
//        printf("-1\n");
//        return 0;
//    }

    //sort(st+1,st+m+1,cmp);

    int res=-1;
    int floor,flat;

    for(int i=1; i<=100; i++)
    {
        int each=i;
        int valid=true;
        for(int j=1; j<=m; j++)
        {
            int k=st[j].k;
            int ff = k/each;
            if(k%each!=0)ff++;
            if(ff!=st[j].f){
                valid=false;
                break;
            }
        }

        if(valid==true){
            int ans = n/each;
            if(n%each!=0)ans++;
            res = ans;
            ss.insert(ans);
        }
    }

    if((int)ss.size()==1)
    {
        printf("%d\n",res);
    }
    else
    {
        printf("-1\n");
    }

    //main();

    return 0;
}
