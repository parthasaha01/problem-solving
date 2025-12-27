#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
string a,b,x;
int la,lb;
int main()
{
    cin>>la>>lb;
    cin>>a>>b;

    int ans=10000000;
    int p = 0;
    for(int i=0; i+la<=lb; i++)
    {
        x = "";
        for(int k=0,j=i; k<la; k++,j++)
        {
            x += b[j];
        }

        if(x.size()<la)break;

        int cnt=0;

        for(int k=0; k<la; k++)
        {
            if(a[k]!=x[k])
            {
                cnt++;
            }
        }

        if(cnt<ans)
        {
            ans=cnt;
            p = i;
        }
    }

    x = "";
    for(int k=0,j=p; k<la; k++,j++)
    {
        x += b[j];
    }

    vv.clear();

    for(int k=0; k<la; k++)
    {
        if(a[k]!=x[k])
        {
            vv.push_back(k+1);
        }
    }

    int sz = vv.size();
    printf("%d\n",ans);

    for(int i=0; i<sz; i++)
    {
        if(i==sz-1){
            printf("%d\n",vv[i]);
        }
        else
        {
            printf("%d ",vv[i]);
        }
    }

    return 0;
}
