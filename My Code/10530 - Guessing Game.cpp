#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int low=1,high=10;
    char s1[15];
    string s;
    bool flag[15];

    for(int i=1; i<=10; i++){
        flag[i]=true;
    }

    while(scanf("%d",&n) && n)
    {
        getchar();
        gets(s1);
        s=s1;

        if(s=="right on")
        {
            if(flag[n]==false){
                printf("Stan is dishonest\n");
            }
            else{
                printf("Stan may be honest\n");
            }

            for(int i=1; i<=10; i++){
                flag[i]=true;
            }
        }
        else if(s=="too high"){
            for(int i=n; i<=10; i++){
                flag[i]=false;
            }
        }
        else{
            for(int i=n; i>=1; i--){
                flag[i]=false;
            }
        }
    }

    return 0;
}
