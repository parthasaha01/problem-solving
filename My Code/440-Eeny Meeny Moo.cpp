#include<bits/stdc++.h>
using namespace std;
int a[155];
int main()
{
    int n,res;

    while(scanf("%d",&n) && n)
    {

        for(int m=1; ; m++)
        {
            for(int i=1; i<=n; i++){
                a[i]=i;
            }

            int pre=1;
            int baki=n;
            a[pre]=0;
            pre++;
            baki--;
            int cnt=0;

            int val;

            while(baki>0)
            {
                if(a[pre]!=0){
                    cnt++;
                    if(cnt==m)
                    {
                        a[pre]=0;
                        baki--;
                        cnt = 0;
                        val=pre;
                    }
                }
                pre++;
                if(pre>n){
                    pre=1;
                }
            }
            if(val==2){
                res = m;
                //flag=1;
                break;
            }
        }

        printf("%d\n",res);
    }

    return 0;
}
