#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int cnt[mx];
set <int, greater <int> > ss;
int main()
{
    int w,k;
    scanf("%d %d",&w,&k);
    ss.insert(0);
    ss.insert(w);
    for(int i=1; i<w; i++)
    {
        scanf("%d",&cnt[i]);
        if(cnt[i]>0)
        {
            ss.insert(i);
        }
    }

    int ans = 0;
    set <int, greater <int> > :: iterator it;
    while(1)
    {
        int cur = 0;
        int flag = 0;

        while(cur<w)
        {

            int des = cur+k;
//            if(des>=w){
//                flag=1;
//                ans++;
//                break;
//            }

//            if(*it>des)
//            {
//                it--;
//            }

            it = ss.upper_bound (des+1);

            //printf("cur %d ans=%d des=%d it=%d\n",cur,ans,des,*it);

            if(*it<w)
            {
                if(*it<=cur)
                {
                    flag = 0;
                    break;
                }

                cur = *it;
                cnt[*it]--;
                if(cnt[*it]==0)
                {
                    ss.erase(*it);
                }
            }
            else
            {
                flag = 1;
                ans++;
                break;
            }
        }

        if(flag==0)break;
    }

    printf("%d\n",ans);

    return 0;
}
