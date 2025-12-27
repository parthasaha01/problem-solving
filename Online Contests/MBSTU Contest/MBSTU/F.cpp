#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ss;

    int n;
    scanf("%d",&n);

    int mx7 = n/7;
    bool flag=false;
    int cnt7=0,cnt4=0;
    for(int i=mx7; i>=0; i--)
    {
        int v7 = i*7;
        int v4 = n-v7;


        if(v4%4==0)
        {
            cnt7=i;
            cnt4=(v4/4);

            //cout << cnt7 << " " << cnt4 << " "<< v7 << " "<< v4 << endl;
            flag=true;
            break;
        }
    }

    if(flag==false)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=1; i<=cnt4; i++){
            ss += '4';
        }
        for(int i=1; i<=cnt7; i++){
            ss += '7';
        }

        cout << ss << endl;
    }
    main();
    return 0;
}
