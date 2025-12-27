#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n,k;

    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }

        int cnt=k,pos1=0;
        //int pos2=0,pos=0;

        for(int i=0; i<n; i++)
        {
            //pos=i;
            if(a[i]<0)
            {
                a[i] = -a[i];
                cnt--;
                pos1=i;
            }
            else
            {
                //pos2=i;
                break;
            }

            if(cnt==0)
            {
                break;
            }
        }

        if(cnt!=0)
        {
            if(cnt%2==1)
            {
                if(pos1+1<n)
                {
                    if(a[pos1]<a[pos1+1])
                    {
                        a[pos1] = -a[pos1];
                    }
                    else
                    {
                        a[pos1+1] = -a[pos1+1];
                    }
                }
                else{
                    a[pos1] = -a[pos1];
                }
            }
        }

        int sum=0;

        for(int i=0; i<n; i++){
            sum += a[i];
        }

        printf("%d\n",sum);
    }

    return 0;
}
