#include<iostream>
using namespace std;
int ara[1025][1025];
int main()
{
    int T,d,n,i,j,Max,x,y,x1,y1,p,k;

    cin >> T;

    while(T--)
    {
        for(i=0; i<1025; i++){
            for(j=0; j<1025; j++){
                ara[i][j]=0;
            }
        }

        Max=0;
        cin >> d >> n;

        for(k=0; k<n; k++)
        {
            cin >> x1 >> y1 >> p;

            for(i=x1-d; i<=x1+d; i++)
            {
                if(i<0 || i>1024)
                    continue;
                for(j=y1-d; j<=y1+d; j++)
                {
                    if(j<0 || j>1024)
                    continue;

                    ara[i][j] += p;

                    if(ara[i][j]>Max)
                    {
                        x=i;
                        y=j;
                        Max=ara[i][j];
                    }
                    else if(ara[i][j]==Max)
                    {
                        if(i<x)
                        {
                            x=i;
                            y=j;
                            Max=ara[i][j];
                        }
                        else if(i==x)
                        {
                            if(j<y)
                            {
                                x=i;
                                y=j;
                                Max=ara[i][j];
                            }
                        }
                    }
                }
            }
        }

        cout << x << " " << y << " " << Max << endl;

    }

    return 0;
}
