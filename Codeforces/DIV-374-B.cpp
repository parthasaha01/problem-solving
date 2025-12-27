#include<bits/stdc++.h>
using namespace std;
char s[105],ss[105];
int v[105];
int main()
{
    int n,k;
    while(scanf("%d %d\n",&n,&k)==2)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            v[i]=strlen(s);
        }
        scanf("%s",ss);
        int sz=strlen(ss);
        sort(v,v+n);

        int minn=0;
        int maxx=0;
        int time=0;
        int cnt=0;
        bool flagmn=false;
        bool flagmx=false;

        for(int i=0; i<n; i++)
        {
            if(v[i]==sz&&!flagmn){
                minn=time+1;
                flagmn=true;
            }
            else if(v[i]>sz)
            {
                if(cnt==0)
                {
                    maxx=time-5;
                }
                else
                {
                    maxx=time;
                }
                flagmx=true;
                break;
            }

            cnt++;
            time++;
            if(cnt==k){
                time+=5;
                cnt=0;
            }
        }

        if(!flagmx)
        {

            if(cnt==0)
            {
                maxx=time-5;
            }
            else
            {
                maxx=time;
            }
        }

        printf("%d %d\n",minn,maxx);
    }

    return 0;
}

/*
10 5
a
b
ab
as
ase
ads
bfc
abcd
efgh
ijkl
ads
*/
