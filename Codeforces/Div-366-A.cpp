#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s[10];
    s[0]="I hate it";
    s[1]="I love it";
    s[2]="I hate that ";
    s[3]="I love that ";
    int n;
    while(scanf("%d",&n)==1)
    {
        int flag=0;
        for(int i=0; i<n-1; i++)
        {
            if(flag==0){
                cout << s[2];
                flag=1;
            }
            else{
                cout << s[3];
                flag=0;
            }
        }

        if(n%2==1){
            cout << s[0] << endl;
        }
        else{
            cout << s[1] << endl;
        }
    }

    return 0;
}
