#include<bits/stdc++.h>
using namespace std;
stack<int>st;
stack<int>qq;
int main()
{
    int q; scanf("%d",&q);
    while(q--)
    {
        int t,x;
        scanf("%d%d",&t,&x);

        if(t==1)
        {
            st.push(x);
        }
        else
        {
            int flag = 0;
            int cnt = 0;

            if(st.empty()==1)
            {
                printf("Sorry\n");
                continue;
            }

            while(!st.empty())
            {
                int v = st.top();
                st.pop();
                qq.push(v);
                cnt++;
                if(v==x)
                {
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                printf("Sorry\n");

                while(!qq.empty())
                {
                    int v = qq.top();
                    qq.pop();
                    st.push(v);
                }
            }
            else
            {
                printf("%d\n",cnt);

            }
            while(!qq.empty())
            {
                qq.pop();
            }
        }
    }

    return 0;
}
