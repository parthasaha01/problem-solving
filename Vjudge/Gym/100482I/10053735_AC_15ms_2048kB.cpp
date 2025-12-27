#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cas = 1 ;
    int n,q;
    string st[100],ss[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);

        for(int i=0; i<n; i++)
        {
            cin>>st[i];
        }
        for(int i=0; i<q; i++)
        {
            cin>>ss[i];
        }
        vector<string>vec;
        for(int i=0; i<q; i++)
        {

            int mx = 0;
            int cnt,c=0,c1=0;
            for(int k=0; k<n; k++)
            {
                cnt = 0 ;
                if(ss[i].size()==st[k].size())
                {
                    if(ss[i]==st[k])
                    {
                        c1 = 1 ;
                        break;
                    }
                    else
                    {
                        for(int j=0; j<ss[i].size(); j++)
                        {
                            if(st[k][j]!=ss[i][j])
                                cnt++;
                        }
                    }

                    if(cnt==1)
                        c++;
                }
            }
            if(c1==1)
                vec.push_back("yes");
            else if(c==1)
                vec.push_back("yes");
            else
                vec.push_back("no");

        }
        printf("Case #%d:\n",cas++);
        for(int i=0; i<vec.size(); i++)
        {
            cout<<vec[i]<<endl;
        }

    }
    return 0;
}




