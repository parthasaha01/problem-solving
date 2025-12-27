#include<bits/stdc++.h>
using namespace std;
vector<int>a,b,c;
queue< vector<int> >qq;
int flag,cnt=0;
void print()
{
    cnt++;
        printf("%d: ",cnt);
        for(int i=0; i<c.size(); i++){
            printf("%d ",c[i]);
        }
        printf("\n");
        getchar();
}
void fun()
{
    //int cnt=0;
    while(!qq.empty())
    {
        a.clear();
        a = qq.front();
        qq.pop();

        int n = a.size();
        int m = b.size();

        int rv=0;

        if(a[n-1]<0)
        {
            rv=1;
            c.clear();
            c=a;
            a.clear();
            for(int i=0; i<n-1; i++){
                a.push_back(c[i]);
            }
        }


        if(a.size()<b.size())continue;

        //cnt++;
        //printf("%d: ",cnt);
//        for(int i=0; i<a.size(); i++){
//            printf("%d ",a[i]);
//        }
//        printf("\n");
        //getchar();

        n = a.size();

        if(a==b){
            flag=1;
            return;
        }

        if(rv==0)
        {
            c.clear();
            c=a;
            reverse(c.begin(),c.end());
            if(c==b){
                flag=1;
                return;
            }

            if(a!=c)
            {
                c.push_back(-1);
                //print();
                cnt++;
                if(cnt<10000)qq.push(c);
            }
            c.clear();
        }

        int p = n/2;

        for(int i=0; i<p; i++)
        {
            c.clear();

            int r = (2*i)+1;
            for(int k=n-1; k>r; k--)
            {
                c.push_back(a[k]);
            }
            for(int x=0,y=r; x<=i; x++,y--)
            {
                int v = a[x]+a[y];
                c.push_back(v);
            }

            //print();

            if(c.size()>=b.size())
            {
                cnt++;
                if(cnt<10000)qq.push(c);

            }
        }

        for(int i=p; i<n-1; i++)
        {
            c.clear();
            int r = i+i+1-n;
            for(int k=0; k<=r; k++)
            {
                c.push_back(a[k]);
            }
            for(int x=r+1,y=n-1; x<=i; x++,y--)
            {
                int v = a[x]+a[y];
                c.push_back(v);
            }

            //print();
            if(c.size()>=b.size())
            {
                cnt++;
                if(cnt<10000)qq.push(c);
            }
        }
    }
}
int main()
{
    int n,m;
    while(scanf("%d",&n)==1)
    {
        flag=0;

        a.clear();
        b.clear();
        c.clear();

        for(int i=1; i<=n; i++)
        {
            int x; scanf("%d",&x);
            a.push_back(x);
        }

        qq.push(a);

        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            int x; scanf("%d",&x);
            b.push_back(x);
        }

        fun();

        if(flag==1)printf("S\n");
        else printf("N\n");
    }
    return 0;
}

