#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans=0,val;
void fun(int pos,int flag,int maxx,int res,int nd)
{
    if(pos>n)
    {
        if(flag==1)
        {
            if(res>=ans)
            {
                if(ans==res)
                {
                    if(a[nd]<a[val])
                    {
                        val=nd;
                    }
                }
                else
                {
                    val = nd;
                    ans = res;
                }
            }
        }

        return;
    }

    if(flag==1)
    {
        if(a[pos]>maxx) fun(pos+1,1,a[pos],res+1,nd);
        else fun(pos+1,1,maxx,res,nd);
    }
    else
    {
        if(a[pos]>maxx) fun(pos+1,0,a[pos],res+1,nd);
        else fun(pos+1,0,maxx,res,nd);

        fun(pos+1,1,maxx,res,pos);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }

    a[0] = 1000000;
    val = 0;
    ans = 0;

    fun(1,0,0,0,0);

    printf("%d\n",a[val]);
}
