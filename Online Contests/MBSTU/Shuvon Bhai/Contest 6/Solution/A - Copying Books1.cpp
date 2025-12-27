#include<iostream>
using namespace std;
int main()
{
    int T,m,k,i;

    cin >> T;

    while(T--)
    {
        cin >> m >> k;

        long p[m],sum=0,part,S,j,cnt,m;
        long ara[m+k];

        for(i=0;i<m;i++)
        {
            cin >> p[i];
            sum+=p[i];
        }

        cnt=k;
        part=sum/cnt;
        S=0;
        j=m+k;
        i=m-1;

        //cout << "partha" << endl;

        line:
        if(i+1==cnt)
        {
            for(;i>=0;i--)
            {
                ara[--j]=p[i];
                ara[--j]=0;
            }
        }
        else
        {

            for(i=m-1; i>=0; i--)
            {
                //cout << "partha" << endl;
                S+=p[i];
                ara[--j]=p[i];

                if(S>=part)
                {
                    --cnt;
                    ara[--j]=0;
                    sum -= S;
                    S=0;
                    part=sum/cnt;
                }

                if(i+1==cnt)
                {
                    goto line;
                }
            }
        }
        cout << ara[1];
        for(i=2; i<m+k; i++)
        {
            if(ara[i]==0)
            {
                cout << " /";
            }
            else
            {
                cout << " " << ara[i];
            }
        }
        cout << endl;
    }

    return 0;
}
