#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long n,m,i,j,flag,coin,diff;

    while(cin >> n >> m)
    {
        if(!n && !m)
            break;

        long head[n],height[m];

        for(i=0;i<n;i++)
            cin >> head[i];

        for(i=0; i<m; i++)
            cin >> height[i];

        if(n>m)
        {
            cout << "Loowater is doomed!" << endl;
            continue;
        }

        sort(head,head+n);
        sort(height,height+m);

        /*for(i=0;i<n;i++)
            cout << head[i] << " ";
        cout << endl;
        for(i=0; i<m; i++)
            cout << height[i] << " ";
        cout << endl;*/

        diff=m-n;
        coin=0;
        flag=1;

        for(i=0,j=0; i<n; j++)
        {
            if(head[i]<=height[j])
            {
                coin += height[j];
                i++;
            }
            else
            {
                diff--;

                if(diff<0)
                {
                    flag=0;
                    break;
                }
            }
        }

        if(flag)
            cout << coin << endl;
        else
           cout << "Loowater is doomed!" << endl;
    }

    return 0;
}
