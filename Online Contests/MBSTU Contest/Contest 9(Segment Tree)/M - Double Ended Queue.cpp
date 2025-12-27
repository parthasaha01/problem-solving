#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
        printf("Case %d:\n",kase);
        int n,m;
        scanf("%d%d",&n,&m);

        deque<int>dq;
        string s;

        for(int i=0; i<m; i++)
        {
            cin >> s;

            if(s=="pushLeft" || s=="pushRight")
            {
                int x;
                cin >> x;

                if(dq.size()==n)
                    printf("The queue is full\n");
                else{
                    if(s=="pushLeft"){
                        dq.push_back(x);
                        printf("Pushed in left: %d\n",x);
                    }
                    else{
                        dq.push_front(x);
                        printf("Pushed in right: %d\n",x);
                    }
                }
            }
            else
            {
                if(dq.size()==0)
                    printf("The queue is empty\n");
                else{
                    if(s=="popLeft"){
                        int x;
                        x=dq.back();
                        dq.pop_back();
                        printf("Popped from left: %d\n",x);
                    }
                    else{
                        int x;
                        x=dq.front();
                        dq.pop_front();
                        printf("Popped from right: %d\n",x);
                    }
                }

            }
        }
    }

    return 0;
}
