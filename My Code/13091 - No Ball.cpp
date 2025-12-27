#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);

    string s[10];

    for(int test=1; test<=T; test++)
    {
        getchar();

        for(int i=0; i<5; i++){
            cin >> s[i];
        }

        int ln,flag;

        for(int i=0; i<5; i++){
            if(s[0][i]=='|'){
                ln=i;
                break;
            }
        }

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(s[i][j]=='<'){
                    if(j<ln){
                        flag=0;
                    }
                    else{
                        flag=1;
                    }
                    goto label;
                }
                else if(s[i][j]=='>'){
                    if(j<ln){
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                    goto label;
                }
            }
        }

        label:

        if(flag){
            printf("Case %d: Thik Ball\n",test);
        }
        else{
            printf("Case %d: No Ball\n",test);
        }
    }

    return 0;
}

