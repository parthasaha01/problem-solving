#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,res;

    while(scanf("%d",&n) && n)
    {

        for(int m=1; ; m++)
        {
            for(int i=1; i<=n; i++)
            {
                a[i]=i;
            }

            int baki=n;
            int pos=2;
            a[1]=0;
            --baki;
            int cnt=0;
            int val;
            while(baki > 0)
            {
                if(pos>n)
                {
                    pos=1;
                }

                if(a[pos]!=0)
                {
                    ++cnt;

                    if(cnt==m)
                    {
                        //printf("%d ",pos);
                        a[pos]=0;
                        cnt=0;
                        val=pos;
                        --baki;
                    }

                }

                pos++;
            }
            //printf("\n");
            if(val==13)
            {
                res=m;
                break;
            }

        }

        printf("%d\n",res);

    }

    return 0;
}
